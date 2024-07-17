#include <iostream>
#include <string>
#include <vector>
#include <base64.hpp>

#include <json/json.h> // Using jsoncpp library

int main() {
    std::string raw_data = "Your raw data here";

    // Ensure raw_data is encoded in UTF-8
    std::vector<unsigned char> utf8Bytes(raw_data.begin(), raw_data.end());

    // Decode the raw_data using Base64
    std::string decodedData = base64::decode(utf8Bytes);

    // Deserialize the decoded data into its original format (e.g., JSON)
    Json::Value deserializedData;
    Json::Reader jsonReader;
    jsonReader.parse(decodedData, deserializedData);

    // Store the deserialized data in a variable
    std::string storedData = deserializedData.toStyledString();

    // Return the stored data
    std::cout << storedData << std::endl;

    return 0;
}