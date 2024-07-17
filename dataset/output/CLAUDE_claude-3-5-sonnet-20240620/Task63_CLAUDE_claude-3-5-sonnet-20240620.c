
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/bio.h>
#include <openssl/evp.h>
#include <jansson.h>

char* base64_decode(const char* input) {
    BIO *bio, *b64;
    size_t decodeLen = strlen(input);
    char* buffer = (char*)malloc(decodeLen + 1);
    
    bio = BIO_new_mem_buf(input, -1);
    b64 = BIO_new(BIO_f_base64());
    bio = BIO_push(b64, bio);
    
    BIO_set_flags(bio, BIO_FLAGS_BASE64_NO_NL);
    int len = BIO_read(bio, buffer, decodeLen);
    buffer[len] = \'\\0\';
    
    BIO_free_all(bio);
    return buffer;
}

json_t* process_request(const char* raw_data) {
    // Ensure raw_data is UTF-8 encoded (assuming it\'s already UTF-8)
    
    // Decode Base64
    char* decoded_data = base64_decode(raw_data);
    
    // Deserialize JSON
    json_error_t error;
    json_t* deserialized_data = json_loads(decoded_data, 0, &error);
    
    free(decoded_data);
    return deserialized_data;
}

int main() {
    const char* raw_data = "eyJuYW1lIjogIkpvaG4gRG9lIiwgImFnZSI6IDMwfQ==";
    json_t* result = process_request(raw_data);
    
    char* json_str = json_dumps(result, JSON_INDENT(2));
    printf("%s\
", json_str);
    
    free(json_str);
    json_decref(result);
    return 0;
}
