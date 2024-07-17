#include <iostream>
#include <nlohmann/json.hpp>

int main() {
    std::string jsonString = "{\"key1\":\"value1\",\"key2\":\"value2\"}";
    nlohmann::json jsonObject = nlohmann::json::parse(jsonString);
    std::cout << "Root element: " << jsonObject.begin().key() << std::endl;
    return 0;
}