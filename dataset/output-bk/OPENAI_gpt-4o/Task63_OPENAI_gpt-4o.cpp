#include <iostream>
#include <cstring>
#include <cstdlib>
#include <json/json.h>
#include <openssl/bio.h>
#include <openssl/evp.h>

std::string base64_decode(const std::string &in) {
    BIO *bio, *b64;
    char *buffer = (char *)malloc(in.size());
    bio = BIO_new_mem_buf(in.c_str(), -1);
    b64 = BIO_new(BIO_f_base64());
    bio = BIO_push(b64, bio);
    int decodeLen = BIO_read(bio, buffer, in.size());
    buffer[decodeLen] = '\0';
    BIO_free_all(bio);
    std::string result(buffer, decodeLen);
    free(buffer);
    return result;
}

int main() {
    std::string requestData = "eyJrZXkiOiAiVmFsdWUifQ==";

    // Step 1 and 2: Retrieve and decode raw data
    std::string decodedData = base64_decode(requestData);

    // Step 3: Deserialize JSON data
    Json::Reader reader;
    Json::Value jsonObject;
    reader.parse(decodedData, jsonObject);

    // Step 4: Store deserialized data in variable and return it
    std::string storedData = jsonObject.toStyledString();
    std::cout << storedData << std::endl;

    return 0;
}