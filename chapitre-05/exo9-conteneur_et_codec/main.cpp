#include <iostream>
#include <string>
#include <vector>

// Structure pour stocker les informations d'une piste (son type et son code de compression)
struct InformationsPiste 
{
    std::string typePiste; // "vide" pour image/vidéo ou "soun" pour audio
    std::string codeCodec; // Code à quatre caractères du codec
};

// Fonction pour transformer une chaîne d'octets hexadécimaux en une liste de nombres entiers
static std::vector<int> convertirHexadécimalEnOctets(const std::string &chaineHex) 
{
    std::vector<int> listeOctets;
    if (chaineHex == "-") 
    {
        return listeOctets;
    }
    
    // Fonction interne pour convertir un caractère hexadécimal en sa valeur numérique
    auto obtenirValeur = [](char caractere) -> int 
    {
        if (caractere >= '0' && caractere <= '9') return caractere - '0';
        if (caractere >= 'a' && caractere <= 'f') return caractere - 'a' + 10;
        if (caractere >= 'A' && caractere <= 'F') return caractere - 'A' + 10;
        return -1;
    };

    // On lit les caractères deux par deux pour former chaque octet
    for (size_t i = 0; i + 1 < chaineHex.size(); i += 2) 
    {
        int valeurHaute = obtenirValeur(chaineHex[i]);
        int valeurBasse = obtenirValeur(chaineHex[i + 1]);
        if (valeurHaute < 0 || valeurBasse < 0) 
        {
            break;
        }
        listeOctets.push_back(valeurHaute * 16 + valeurBasse);
    }
    return listeOctets;
}

// Fonction pour vérifier si un motif d'octets précis se trouve bien au bon endroit dans le fichier
static bool verifierMotifOctets(const std::vector<int> &octetsFichier, size_t positionDebut, const std::vector<int> &motifRecherche) {
    if (octetsFichier.size() < positionDebut + motifRecherche.size()) 
    {
        return false;
    }
    for (size_t i = 0; i < motifRecherche.size(); ++i) 
    {
        if (octetsFichier[positionDebut + i] != motifRecherche[i]) 
        {
            return false;
        }
    }
    return true;
}

// Fonction pour identifier le conteneur du média en testant les règles dans l'ordre strict
static std::string identifierConteneur(const std::vector<int> &octetsFichier) 
{
    const size_t tailleTotale = octetsFichier.size();

    // Règle 1 : MP4 (la signature "ftyp" se trouve de l'octet 4 à 7)[cite: 40]
    if (tailleTotale >= 12 && verifierMotifOctets(octetsFichier, 4, {0x66, 0x74, 0x79, 0x70})) 
    {
        return "MP4";
    }
    // Règle 2 : WEBM[cite: 40]
    if (tailleTotale >= 4 && verifierMotifOctets(octetsFichier, 0, {0x1A, 0x45, 0xDF, 0xA3})) 
    {
        return "WEBM";
    }
    // Règle 3 : WAV (contient "RIFF" au début et "WAVE" à l'indice 8)[cite: 40]
    if (tailleTotale >= 12 && verifierMotifOctets(octetsFichier, 0, {0x52, 0x49, 0x46, 0x46}) && verifierMotifOctets(octetsFichier, 8, {0x57, 0x41, 0x56, 0x45})) 
    {
        return "WAV";
    }
    // Règle 4 : OGG[cite: 40]
    if (tailleTotale >= 4 && verifierMotifOctets(octetsFichier, 0, {0x4F, 0x67, 0x67, 0x53})) 
    {
        return "OGG";
    }
    // Règle 5 : FLAC
    if (tailleTotale >= 4 && verifierMotifOctets(octetsFichier, 0, {0x66, 0x4C, 0x61, 0x43})) 
    {
        return "FLAC";
    }
    // Règles 6 & 7 : MP3
    if (tailleTotale >= 3 && verifierMotifOctets(octetsFichier, 0, {0x49, 0x44, 0x33})) 
    {
        return "MP3";
    }
    if (tailleTotale >= 2 && octetsFichier[0] == 0xFF && octetsFichier[1] >= 0xE0) 
    {
        return "MP3";
    }

    // Si aucun conteneur ne correspond
    return "INCONNU";
}

// Fonction pour traduire le nom brut d'un codec selon la table officielle de l'énoncé
static std::string nommerCodec(const std::string &codeBrut) 
{
    if (codeBrut == "mp4a") return "aac";
    if (codeBrut == "Opus" || codeBrut == "opus") return "opus";
    if (codeBrut == "avc1" || codeBrut == "avc3") return "h264";
    if (codeBrut == "hvc1" || codeBrut == "hev1") return "h265";
    if (codeBrut == "vp08") return "vp8";
    if (codeBrut == "vp09") return "vp9";
    if (codeBrut == "mp4v") return "mpeg4";
    if (codeBrut == ".mp3") return "mp3";
    if (codeBrut == "twos" || codeBrut == "sowt" || codeBrut == "lpcm") return "pcm";
    
    // Si le code est absent de la table, on le garde tel quel
    return codeBrut;
}

// Fonction pour vérifier si un code de codec vidéo est lisible par le lecteur
static bool estCodecLisible(const std::string &codeCodec) 
{
    return codeCodec == "mjpa" || codeCodec == "jpeg" || codeCodec == "MJPG" || 
           codeCodec == "avc1" || codeCodec == "avc3" || codeCodec == "hvc1" || 
           codeCodec == "hev1" || codeCodec == "av01";
}

int main() 
{
    // Désactivation de la synchronisation pour accélérer les entrées/sorties
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    // Variable entière pour stocker le nombre total de fichiers à analyser
    int nombreFichiers = 0;
    std::cin >> nombreFichiers;

    // Compteurs pour le bilan final
    int compteurMp4 = 0;
    int compteurLisibles = 0;
    int compteurInconnus = 0;

    // Boucle pour traiter chaque fichier un par un
    for (int i = 0; i < nombreFichiers; ++i) 
    {
        std::string nomFichier;
        std::string chaineHexadecimale;
        int nombrePistes = 0;

        std::cin >> nomFichier >> chaineHexadecimale >> nombrePistes;

        // On lit toujours l'intégralité des pistes de la ligne, même si le fichier n'est pas un MP4
        std::vector<InformationsPiste> listePistes(static_cast<size_t>(nombrePistes));
        for (int k = 0; k < nombrePistes; ++k) 
        {
            std::cin >> listePistes[static_cast<size_t>(k)].typePiste 
                     >> listePistes[static_cast<size_t>(k)].codeCodec;
        }

        // Identification du conteneur grâce aux premiers octets
        std::string conteneurReconnu = identifierConteneur(convertirHexadécimalEnOctets(chaineHexadecimale));
        std::cout << nomFichier << " " << conteneurReconnu << "\n";

        if (conteneurReconnu == "INCONNU") 
        {
            compteurInconnus++;
        }

        // Les détails des pistes et du lecteur ne s'affichent que si le conteneur est un MP4[cite: 41]
        if (conteneurReconnu != "MP4") 
        {
            continue; 
        }

        compteurMp4++;

        // Affichage des informations de chaque piste du fichier MP4
        for (int k = 0; k < nombrePistes; ++k) 
        {
            const InformationsPiste &pisteActuelle = listePistes[static_cast<size_t>(k)];
            std::string typeAffichage = (pisteActuelle.typePiste == "vide" ? "VIDEO" : "AUDIO");
            std::cout << nomFichier << " PISTE " << (k + 1) << " " << typeAffichage << " " << nommerCodec(pisteActuelle.codeCodec) << "\n";
        }

        // Le lecteur analyse uniquement la première piste vidéo ("vide") du MP4[cite: 41]
        std::string verdictLecteur = "SANS_IMAGE";
        for (int k = 0; k < nombrePistes; ++k) 
        {
            const InformationsPiste &pisteActuelle = listePistes[static_cast<size_t>(k)];
            if (pisteActuelle.typePiste == "vide") 
            {
                verdictLecteur = estCodecLisible(pisteActuelle.codeCodec) ? "LISIBLE" : "ECHEC";
                break; // On s'arrête dès qu'on a trouvé la première piste vidéo
            }
        }

        std::cout << nomFichier << " LECTEUR " << verdictLecteur << "\n";

        if (verdictLecteur == "LISIBLE") 
        {
            compteurLisibles++;
        }
    }

    // Affichage des bilans finaux obligatoires exigés par la plateforme
    std::cout << "MP4 " << compteurMp4 << "\n";
    std::cout << "LISIBLES " << compteurLisibles << "\n";
    std::cout << "INCONNUS " << compteurInconnus << "\n";

    return 0;
}
