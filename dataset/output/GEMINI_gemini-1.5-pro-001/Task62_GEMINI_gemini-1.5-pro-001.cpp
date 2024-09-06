#include <iostream>
#include <string>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

// Function to get the root element of a JSON string
nlohmann::json getRootElement(const std::string& jsonString) {
    try {
        return json::parse(jsonString);
    } catch (const json::exception& e) {
        std::cerr << "Invalid JSON string: " << e.what() << std::endl;
        return nullptr;
    }
}

int main() {
    std::string jsonString = "{\"name\": \"John\", \"age\": 30, \"city\": \"New York\"}";
    nlohmann::json rootElement = getRootElement(jsonString);

    if (!rootElement.is_null()) {
        std::cout << rootElement.dump(4) << std::endl;
    }

    return 0;
}