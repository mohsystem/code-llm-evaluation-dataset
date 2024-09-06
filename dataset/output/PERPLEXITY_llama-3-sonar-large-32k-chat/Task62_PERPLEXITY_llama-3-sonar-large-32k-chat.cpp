// Note: This code uses the nlohmann/json library, which is a popular JSON library for C++.
// You need to install it before compiling the code.

#include <nlohmann/json.hpp>
#include <iostream>

using json = nlohmann::json;

int main() {
    std::string jsonString = "{\"name\":\"John\", \"age\":30, \"city\":\"New York\"}";
    json jsonObject = json::parse(jsonString);
    std::cout << jsonObject.type_name() << std::endl;
    return 0;
}