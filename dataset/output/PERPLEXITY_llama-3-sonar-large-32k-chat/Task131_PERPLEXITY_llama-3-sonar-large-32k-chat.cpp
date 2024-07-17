#include <iostream>
#include <fstream>
#include <string>

class DeserializeData {
public:
    static void deserializeData(const std::string& data) {
        try {
            std::istringstream iss(data);
            std::string token;
            iss >> token;
            std::cout << "Deserialized data: " << token << std::endl;
        } catch (const std::exception& e) {
            std::cerr << "Error deserializing data: " << e.what() << std::endl;
        }
    }
};

int main() {
    std::cout << "Enter serialized data: ";
    std::string data;
    std::getline(std::cin, data);
    DeserializeData::deserializeData(data);
    return 0;
}