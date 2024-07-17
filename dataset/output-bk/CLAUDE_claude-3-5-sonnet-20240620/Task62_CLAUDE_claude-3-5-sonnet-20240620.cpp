
#include <iostream>
#include <string>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

json parse_json(const std::string& json_string) {
    try {
        return json::parse(json_string);
    } catch (json::parse_error& e) {
        std::cerr << "JSON parse error: " << e.what() << std::endl;
        return json();
    }
}

int main() {
    std::string json_string = "{\\"name\\":\\"John\\",\\"age\\":30,\\"city\\":\\"New York\\"}";
    json root_element = parse_json(json_string);
    
    if (!root_element.is_null()) {
        std::cout << "Root element: " << root_element.dump() << std::endl;
    }
    
    return 0;
}
