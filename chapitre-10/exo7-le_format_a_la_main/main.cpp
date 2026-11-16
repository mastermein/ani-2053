#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>

int main() 
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    if (!(std::cin >> T)) 
    {
        return 0;
    }

    std::vector<unsigned char> bytes(T);
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
        bytes[i] = static_cast<unsigned char>(val);
    }


    if (T < 8) 
    {
        std::cout << "TRONQUE\n";
        return 0;
    }


    return 0;
}
