#include <iostream>
#include <fstream>
#include <string>

class DeserializeData {
public:
    static void deserializeData(const std::string& data) {
        std::istringstream iss(data);
        std::string token;
        while (std::getline(iss, token, ':')) {
            std::string key, value;
            std::getline(iss, key, ':');
            std::getline(iss, value, ':');
            std::cout << "Deserialized data: " << key << " = " << value << std::endl;
        }
    }
};

int main() {
    std::cout << "Enter serialized data (in key-value format, e.g., key1:value1:key2:value2): ";
    std::string data;
    std::getline(std::cin, data);
    DeserializeData::deserializeData(data);
    return 0;
}