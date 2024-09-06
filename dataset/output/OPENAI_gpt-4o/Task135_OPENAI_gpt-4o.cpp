#include <iostream>
#include <random>
#include <sstream>
#include <iomanip>
#include <openssl/sha.h>

class CSRFProtection {
    private:
        std::string token;

    public:
        std::string generateToken(const std::string& sessionId) {
            std::random_device rd;
            std::mt19937_64 gen(rd());
            std::uniform_int_distribution<unsigned long long> dis;
            unsigned long long randomValue = dis(gen);
            std::stringstream ss;
            ss << std::hex << std::setw(16) << std::setfill('0') << randomValue;

            unsigned char hash[SHA256_DIGEST_LENGTH];
            SHA256(reinterpret_cast<const unsigned char*>(ss.str().c_str()), ss.str().length(), hash);
            std::stringstream sha256hex;
            for (int i = 0; i < SHA256_DIGEST_LENGTH; ++i) {
                sha256hex << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(hash[i]);
            }
            token = sha256hex.str() + sessionId;
            return token;
        }

        bool validateToken(const std::string& token, const std::string& sessionId) {
            return token == this->token + sessionId;
        }
};

int main() {
    CSRFProtection csrf;
    std::string sessionId = "12345ABC";
    std::string token = csrf.generateToken(sessionId);
    std::cout << "Token: " << token << std::endl;
    std::cout << "Validation: " << csrf.validateToken(token, sessionId) << std::endl;
    return 0;
}