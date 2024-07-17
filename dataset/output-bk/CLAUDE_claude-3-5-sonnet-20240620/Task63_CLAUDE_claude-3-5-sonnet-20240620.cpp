
#include <iostream>
#include <string>
#include <vector>
#include <boost/beast/core/detail/base64.hpp>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

std::string base64_decode(const std::string& input) {
    std::vector<unsigned char> decoded;
    boost::beast::detail::base64::decode(decoded, input);
    return std::string(decoded.begin(), decoded.end());
}

json process_request(const std::string& raw_data) {
    try {
        // Ensure raw_data is UTF-8 encoded (assuming it\'s already UTF-8)
        
        // Decode Base64
        std::string decoded_data = base64_decode(raw_data);
        
        // Deserialize JSON
        json deserialized_data = json::parse(decoded_data);
        
        // Return the deserialized data
        return deserialized_data;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return json();
    }
}

int main() {
    std::string raw_data = "eyJuYW1lIjogIkpvaG4gRG9lIiwgImFnZSI6IDMwfQ==";
    json result = process_request(raw_data);
    std::cout << result.dump(2) << std::endl;
    return 0;
}
