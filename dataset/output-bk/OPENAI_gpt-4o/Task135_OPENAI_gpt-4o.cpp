#include <iostream>
#include <string>
#include <ctime>
#include <sstream>
#include <openssl/hmac.h>
#include <openssl/rand.h>

std::string generate_csrf_token() {
    unsigned char key[32];
    RAND_bytes(key, sizeof(key));

    unsigned char out[EVP_MAX_MD_SIZE];
    unsigned int out_len;

    HMAC(EVP_sha256(), "SuperSecretKey", 13, key, sizeof(key), out, &out_len);

    std::ostringstream oss;
    for (unsigned int i = 0; i < out_len; i++) {
        oss << std::hex << static_cast<int>(out[i]);
    }

    return oss.str();
}

int main() {
    std::string csrf_token = generate_csrf_token();
    std::cout << "Generated CSRF Token: " << csrf_token << std::endl;
    // This is a mock-up example. Add HTTP handling using a library like cpp-httplib for a full example.

    return 0;
}