
#include <iostream>
#include <string>
#include <vector>
#include <nlohmann/json.hpp>
#include <boost/beast/core/detail/base64.hpp>

using json = nlohmann::json;

json process_request(const std::string& raw_data) {
    // Ensure raw_data is UTF-8 encoded (assuming it's already UTF-8 in C++)
    
    // Decode the raw_data using Base64
    std::string decoded_data;
    decoded_data.resize(boost::beast::detail::base64::decoded_size(raw_data.size()));
    auto result = boost::beast::detail::base64::decode(&decoded_data[0], raw_data.data(), raw_data.size());
    decoded_data.resize(result.first);
    
    // Deserialize the decoded data (assuming JSON in this example)
    json deserialized_data = json::parse(decoded_data);
    
    // Store the deserialized data in a variable
    json stored_data = deserialized_data;
    
    // Return the stored data
    return stored_data;
}

int main() {
    std::string raw_input = "eyJuYW1lIjogIkpvaG4gRG9lIiwgImFnZSI6IDMwfQ==";
    json result = process_request(raw_input);
    std::cout << result.dump(2) << std::endl;
    return 0;
}
