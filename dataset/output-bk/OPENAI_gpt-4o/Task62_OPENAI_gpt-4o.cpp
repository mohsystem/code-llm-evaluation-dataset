#include <iostream>
#include <json/json.h>

int main() {
    std::string jsonString = "{\"name\":\"John\", \"age\":30, \"car\":null}";
    Json::CharReaderBuilder readerBuilder;
    Json::Value root;
    std::string errs;
    std::istringstream s(jsonString);
    std::string rootKey;

    Json::parseFromStream(readerBuilder, s, &root, &errs);
    for (const auto& key : root.getMemberNames()) {
        rootKey = key;
        break;
    }
    
    std::cout << "Root Element: " << rootKey << std::endl;
    return 0;
}