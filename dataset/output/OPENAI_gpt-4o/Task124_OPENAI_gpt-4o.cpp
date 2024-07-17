#include <iostream>
#include <string>
#include <openssl/evp.h>
#include <openssl/bio.h>
#include <openssl/buffer.h>

class SecureData {
    std::string encodedData;
    
    std::string base64_encode(const std::string &in) {
        BIO *bio, *b64;
        BUF_MEM *bufferPtr;
        b64 = BIO_new(BIO_f_base64());
        bio = BIO_new(BIO_s_mem());
        BIO_push(b64, bio);
        BIO_write(b64, in.c_str(), in.length());
        BIO_flush(b64);
        BIO_get_mem_ptr(b64, &bufferPtr);
        std::string encoded((*bufferPtr).data, (*bufferPtr).length);
        BIO_free_all(b64);
        return encoded;
    }

    std::string base64_decode(const std::string &in) {
        BIO *bio, *b64;
        char *buffer = (char *)malloc(in.length());
        memset(buffer, 0, in.length());
        b64 = BIO_new(BIO_f_base64());
        bio = BIO_new_mem_buf(in.c_str(), in.length());
        BIO_push(b64, bio);
        BIO_read(b64, buffer, in.length());
        std::string decoded(buffer);
        free(buffer);
        BIO_free_all(b64);
        return decoded;
    }

public:
    SecureData(std::string data) : encodedData(base64_encode(data)) {}

    std::string decodeData() {
        return base64_decode(this->encodedData);
    }

    std::string getEncodedData() {
        return this->encodedData;
    }
};

int main() {
    SecureData sd("4111-1111-1111-1111");
    std::cout << "Encoded Data (C++): " << sd.getEncodedData() << std::endl;
    std::cout << "Decoded Data (C++): " << sd.decodeData() << std::endl;
    return 0;
}