
#include <iostream>
#include <string>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

int main() {
    std::string serialized_data;
    std::cout << "Enter serialized data (JSON format): ";
    std::getline(std::cin, serialized_data);

    try {
        json deserialized_data = json::parse(serialized_data);
        std::cout << "Deserialized data:" << std::endl;
        std::cout << deserialized_data.dump(2) << std::endl;
    } catch (json::parse_error& e) {
        std::cout << "Error: Invalid JSON data" << std::endl;
    }

    return 0;
}
