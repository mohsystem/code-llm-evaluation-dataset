
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

std::vector<unsigned char> base64_decode(const std::string& input) {
    const std::string base64_chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
    std::vector<unsigned char> ret;
    int val = 0, valb = -8;
    for (unsigned char c : input) {
        if (c == \'=\') break;
        if (std::string::npos == base64_chars.find(c)) continue;
        val = (val << 6) + base64_chars.find(c);
        valb += 6;
        if (valb >= 0) {
            ret.push_back(char((val >> valb) & 0xFF));
            valb -= 8;
        }
    }
    return ret;
}

int main() {
    std::string serialized_data;
    std::cout << "Enter the serialized data: ";
    std::getline(std::cin, serialized_data);

    try {
        std::vector<unsigned char> decoded_data = base64_decode(serialized_data);
        std::string deserialized_data(decoded_data.begin(), decoded_data.end());
        std::cout << "Deserialized data: " << deserialized_data << std::endl;
    } catch (...) {
        std::cout << "Error: Invalid input or deserialization failed." << std::endl;
    }

    return 0;
}
