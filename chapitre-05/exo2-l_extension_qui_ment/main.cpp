#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>

// Fonction pour extraire l'extension d'un nom de fichier et la mettre en minuscules
std::string recupererExtension(const std::string& nomFichier) 
{
    size_t point = nomFichier.find_last_of('.');
    // S'il n'y a pas de point ou s'il est tout à la fin, il n'y a pas d'extension
    if (point == std::string::npos || point == nomFichier.length() - 1) 
    {
        return "";
    }
    std::string ext = nomFichier.substr(point + 1);
    // Transformer l'extension en minuscules
    for (char& c : ext) 
    {
        c = std::tolower(static_cast<unsigned char>(c));
    }
    return ext;
}

// Fonction pour transformer une chaîne d'octets hexadécimaux en une liste de nombres (octets)
std::vector<unsigned char> convertirHexEnOctets(const std::string& chaineHex) 
{
    std::vector<unsigned char> octets;
    if (chaineHex == "-") 
    {
        return octets;
    }
    // On lit les caractères deux par deux (ex: "89" puis "50")
    for (size_t i = 0; i + 1 < chaineHex.length(); i += 2) 
    {
        std::string morceau = chaineHex.substr(i, 2);
        unsigned char valeur = static_cast<unsigned char>(std::stoul(morceau, nullptr, 16));
        octets.push_back(valeur);
    }
    return octets;
}

// Fonction pour vérifier si une suite d'octets correspond au début d'un fichier à un endroit précis
bool verifierDebut(const std::vector<unsigned char>& octets, size_t position, const std::vector<unsigned char>& motif) 
{
    if (octets.size() < position + motif.size()) 
    {
        return false;
    }
    for (size_t i = 0; i < motif.size(); ++i) {
        if (octets[position + i] != motif[i]) 
        {
            return false;
        }
    }
    return true;
}

// Fonction qui analyse la taille et les premiers octets pour deviner le format réel du fichier
std::string identifierFormat(long long taille, const std::vector<unsigned char>& b) 
{
    // Règle 1 : Si la taille est trop petite, on refuse
    if (taille < 4) 
    {
        return "REFUSE";
    }

    // Règle 2 : PNG (commence par 89 50 4E 47 et taille >= 8)
    if (taille >= 8 && verifierDebut(b, 0, {0x89, 0x50, 0x4E, 0x47})) 
    {
        return "PNG";
    }

    // Règle 3 : JPEG (commence par FF D8 FF)
    if (verifierDebut(b, 0, {0xFF, 0xD8, 0xFF})) 
    {
        return "JPEG";
    }

    // Règle 4 : BMP (commence par 42 4D, c'est-à-dire "BM")
    if (verifierDebut(b, 0, {0x42, 0x4D})) 
    {
        return "BMP";
    }

    // Autres formats (QOI, GIF, ICO, HDR, EXR, PBM/PGM/PPM, TGA, SVG...)
    if (verifierDebut(b, 0, {0x71, 0x6F, 0x69, 0x66})) return "QOI";
    if (verifierDebut(b, 0, {0x47, 0x49, 0x46, 0x38})) return "GIF";
    
    if (b.size() >= 4 && b[0] == 0x00 && b[1] == 0x00 && (b[2] == 0x01 || b[2] == 0x02) && b[3] == 0x00) 
    {
        return "ICO";
    }

    if (taille >= 10 && verifierDebut(b, 0, {0x23, 0x3F})) 
    {
        return "HDR";
    }

    if (verifierDebut(b, 0, {0x76, 0x2F, 0x31, 0x01})) 
    {
        return "EXR";
    }

    if (b.size() >= 2 && b[0] == 0x50) 
    {
        unsigned char b1 = b[1];
        if (b1 == 0x31 || b1 == 0x34) return "PBM";
        if (b1 == 0x32 || b1 == 0x35) return "PGM";
        if (b1 == 0x33 || b1 == 0x36) return "PPM";
    }

    if (taille >= 18 && b.size() >= 3) 
    {
        unsigned char b2 = b[2];
        if (b2 == 0x00 || b2 == 0x01 || b2 == 0x02 || b2 == 0x03 ||
            b2 == 0x09 || b2 == 0x0A || b2 == 0x0B) 
            {
            return "TGA";
            }
    }

    // Gestion du SVG (on saute les espaces ou caractères invisibles au début)
    size_t idx = 0;
    if (b.size() >= 3 && b[0] == 0xEF && b[1] == 0xBB && b[2] == 0xBF) 
    {
        idx = 3;
    }
    while (idx < b.size() && (b[idx] == 0x20 || b[idx] == 0x09 || b[idx] == 0x0A || b[idx] == 0x0D)) 
    {
        idx++;
    }
    if (verifierDebut(b, idx, {0x3C, 0x3F, 0x78, 0x6D, 0x6C}) || verifierDebut(b, idx, {0x3C, 0x73, 0x76, 0x67})) 
    {
        return "SVG";
    }
    
    // Si aucun format ne correspond
    return "REFUSE";
}

// Fonction pour vérifier si l'extension du nom correspond bien au format réel du fichier
bool estExtensionValide(const std::string& format, const std::string& ext) 
{
    if (ext.empty()) return false;

    if (format == "PNG")  return (ext == "png");
    if (format == "JPEG") return (ext == "jpg" || ext == "jpeg");
    if (format == "BMP")  return (ext == "bmp");
    if (format == "QOI")  return (ext == "qoi");
    if (format == "GIF")  return (ext == "gif");
    if (format == "ICO")  return (ext == "ico" || ext == "cur");
    if (format == "HDR")  return (ext == "hdr");
    if (format == "EXR")  return (ext == "exr");
    if (format == "PBM")  return (ext == "pbm");
    if (format == "PGM")  return (ext == "pgm");
    if (format == "PPM")  return (ext == "ppm");
    if (format == "TGA")  return (ext == "tga");
    if (format == "SVG")  return (ext == "svg");

    return false;
}

int main() 
{
    // Optimisation des entrées/sorties pour aller plus vite
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int nombreFichiers = 0;
    if (!(std::cin >> nombreFichiers)) 
    {
        std::cout << "LUS 0\nMENSONGES 0\nREFUSES 0\n";
        return 0;
    }

    int totalLus = 0;
    int totalMensonges = 0;
    int totalRefuses = 0;

    // Traitement de chaque fichier un par un
    for (int i = 0; i < nombreFichiers; ++i) 
    {
        std::string nom;
        long long taille = 0;
        std::string chaineHex;

        std::cin >> nom >> taille >> chaineHex;

        std::vector<unsigned char> octets = convertirHexEnOctets(chaineHex);
        std::string ext = recupererExtension(nom);
        std::string formatReel = identifierFormat(taille, octets);

        if (formatReel == "REFUSE") 
        {
            std::cout << nom << " REFUSE\n";
            totalRefuses++;
        } else 
        {
            totalLus++;
            // On vérifie si l'extension ment ou dit la vérité
            if (estExtensionValide(formatReel, ext)) 
            {
                std::cout << nom << " " << formatReel << " OK\n";
            } else 
            {
                std::cout << nom << " " << formatReel << " MENT\n";
                totalMensonges++;
            }
        }
    }

    // Affichage des bilans obligatoires à la fin
    std::cout << "LUS " << totalLus << "\n";
    std::cout << "MENSONGES " << totalMensonges << "\n";
    std::cout << "REFUSES " << totalRefuses << "\n";

    return 0;
}