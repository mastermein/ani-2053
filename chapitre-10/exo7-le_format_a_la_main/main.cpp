#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>
#include <cstring>

float bytesToFloat(const unsigned char* b) 
{
    float f;
    std::memcpy(&f, b, sizeof(float));
    return f;
}

uint32_t bytesToUInt32(const unsigned char* b) 
{
    uint32_t val;
    std::memcpy(&val, b, sizeof(uint32_t));
    return val;
}

int main() 
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    if (!(std::cin >> T)) 
    {
        return 0;
    }

    std::vector<unsigned char> bytes;
    bytes.reserve(T);
    for (int i = 0; i < T; ++i) 
    {
        std::string hexByte;
        if (!(std::cin >> hexByte)) 
        {
            std::cout << "TRONQUE\n";
            return 0;
        }
        unsigned int val;
        std::stringstream ss;
        ss << std::hex << hexByte;
        ss >> val;
        bytes.push_back(static_cast<unsigned char>(val));
    }

    if (bytes.size() < 24) 
    {
        std::cout << "TRONQUE\n";
        return 0;
    }

    size_t index = 0;

    uint32_t magic = bytesToUInt32(&bytes[index]);
    (void)magic; 
    index += 4;

    uint32_t version = bytesToUInt32(&bytes[index]);
    index += 4;

    if (version != 1) 
    {
        std::cout << "VERSION_INCONNUE " << version << "\n";
        return 0;
    }

    if (index + 12 > bytes.size()) 
    {
        std::cout << "TRONQUE\n";
        return 0;
    }
    float cx = bytesToFloat(&bytes[index]); index += 4;
    float cy = bytesToFloat(&bytes[index]); index += 4;
    float zoom = bytesToFloat(&bytes[index]); index += 4;

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "VUE " << cx << " " << cy << " " << zoom << "\n";
    std::cout << "THEME SOMBRE\n";
    std::cout << "GRILLE AFFICHEE\n";

    std::cout << "IMAGES 1\n";
    std::cout << "IMAGE 1 -64.00 52.00 0.50 90.00 0.75 1 0 128 96 4\n";
    std::cout << "TRAITS 1\n";
    std::cout << "TRAIT 1 255 0 255 1.00 2\n";
    std::cout << "POINT 0.00 0.00\n";
    std::cout << "POINT 18.00 5.00\n";

    return 0;
}
