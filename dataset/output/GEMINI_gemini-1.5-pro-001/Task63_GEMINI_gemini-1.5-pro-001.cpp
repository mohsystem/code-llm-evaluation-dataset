#include <iostream>
#include <string>
#include <vector>
#include <base64/base64.h>

std::string processRequest(const std::string& rawData) {
    // Decode the raw_data using Base64
    std::string decodedData = base64_decode(rawData);

    // Deserialize the decoded data
    // ... Implementation for deserialization (replace with your logic)

    return decodedData;
}

int main() {
    // Example usage:
    std::string rawData = "eyJtZXNzYWdlIjogIkhlbGxvIHdvcmxkIn0=";
    std::string processedData = processRequest(rawData);
    std::cout << processedData << std::endl;

    return 0;
}