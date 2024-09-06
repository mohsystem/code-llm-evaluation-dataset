
#include <iostream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

json parse_json_and_get_root(const std::string& json_string) {
    try {
        return json::parse(json_string);
    } catch (json::parse_error& e) {
        return nullptr;
    }
}

int main() {
    std::string json_string = R"({"name": "John", "age": 30, "city": "New York"})";
    json root_element = parse_json_and_get_root(json_string);
    
    if (root_element != nullptr) {
        std::cout << root_element.dump(4) << std::endl;
    } else {
        std::cout << "Failed to parse JSON" << std::endl;
    }

    return 0;
}
