#include <iostream>
#include <string>
#include "json/json.h"

int main() {
    std::string jsonString = "{\"name\": \"John\", \"age\": 30, \"city\": \"New York\"}";
    
    Json::CharReaderBuilder readerBuilder;
    Json::CharReader* reader = readerBuilder.newCharReader();
    Json::Value root;
    std::string errs;
    
    bool parsingSuccessful = reader->parse(jsonString.c_str(), jsonString.c_str() + jsonString.size(), &root, &errs);
    delete reader;

    if (!parsingSuccessful) {
        std::cerr << "Failed to parse the JSON : " << errs << std::endl;
        return 1;
    }
    
    std::cout << root.toStyledString() << std::endl;
    return 0;
}