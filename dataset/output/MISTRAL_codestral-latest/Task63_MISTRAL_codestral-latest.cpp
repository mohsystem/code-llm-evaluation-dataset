// C++
#include <iostream>
#include <base64.h>
#include <json/json.h>

std::string processRequest(const std::string& rawData) {
    std::string decodedString = base64_decode(rawData);

    Json::Value root;
    Json::Reader reader;
    reader.parse(decodedString, root);

    Json::StreamWriterBuilder builder;
    builder["indentation"] = "";
    return Json::writeString(builder, root);
}