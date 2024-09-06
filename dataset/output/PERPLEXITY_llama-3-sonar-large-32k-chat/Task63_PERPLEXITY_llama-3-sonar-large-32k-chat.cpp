#include <iostream>
#include <string>
#include <vector>
#include <base64/decode.hpp>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

json processRequest(const std::string& request) {
    std::string raw_data = request;
    std::vector<unsigned char> decoded_data = base64::decode(raw_data);
    std::string deserialized_data(decoded_data.begin(), decoded_data.end());
    return json::parse(deserialized_data);
}