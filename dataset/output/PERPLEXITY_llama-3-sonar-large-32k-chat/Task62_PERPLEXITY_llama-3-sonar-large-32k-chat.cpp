#include <iostream>
#include <json/json.h>

int main() {
    const char *json_string = "{\"name\":\"John\", \"age\":30, \"city\":\"New York\"}";
    Json::Value root;
    Json::Reader reader;
    bool parsingSuccessful = reader.parse(json_string, root);
    if (parsingSuccessful) {
        std::cout << "Root element: " << root.getMemberNames()[0] << std::endl;
    } else {
        std::cout << "Error parsing JSON" << std::endl;
    }
    return 0;
}