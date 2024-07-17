#include <iostream>
#include <string>
#include <json/json.h>

int main() {
    std::string jsonString = "{\"name\": \"John\", \"age\": 30}";
    Json::CharReaderBuilder readerBuilder;
    Json::CharReader* reader = readerBuilder.newCharReader();
    Json::Value root;
    std::string errors;

    bool parsingSuccessful = reader->parse(jsonString.c_str(), jsonString.c_str() + jsonString.length(), &root, &errors);
    delete reader;

    if (parsingSuccessful) {
        std::string name = root["name"].asString();
        int age = root["age"].asInt();
        std::cout << "Name: " << name << std::endl;
        std::cout << "Age: " << age << std::endl;
    } else {
        std::cout << "Error parsing JSON: " << errors << std::endl;
    }

    return 0;
}