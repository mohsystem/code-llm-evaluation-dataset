#include <iostream>
#include <iomanip>
#include <sstream>
#include <openssl/sha.h>
#include <cstring>

int main() {
    std::string cert = "sample_certificate"; // Replace with actual SSL certificate content
    std::string knownHash = "known_hash"; // Replace with actual known hash
    
    unsigned char digest[SHA256_DIGEST_LENGTH];
    SHA256((unsigned char*)&cert[0], cert.size(), (unsigned char*)&digest);

    std::ostringstream oss;
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        oss << std::hex << std::setw(2) << std::setfill('0') << (int)digest[i];
    }
    std::string hash = oss.str();
    
    if (hash == knownHash) {
        std::cout << "C++: Certificate matches the known hash." << std::endl;
    } else {
        std::cout << "C++: Certificate does not match the known hash." << std::endl;
    }
    
    return 0;
}