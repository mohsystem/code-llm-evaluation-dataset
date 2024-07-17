#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <jansson.h>
#include <openssl/bio.h>
#include <openssl/evp.h>

char* base64_decode(const char* base64_encoded) {
    BIO *bio, *b64;
    int decode_len = strlen(base64_encoded);
    char *buffer = (char *)malloc(decode_len);
    bio = BIO_new_mem_buf(base64_encoded, -1);
    b64 = BIO_new(BIO_f_base64());
    bio = BIO_push(b64, bio);
    decode_len = BIO_read(bio, buffer, strlen(base64_encoded));
    buffer[decode_len] = '\0';
    BIO_free_all(bio);
    return buffer;
}

int main() {
    const char *requestData = "eyJrZXkiOiAiVmFsdWUifQ==";
    
    // Step 1 and 2: Retrieve and decode raw data
    char *decodedData = base64_decode(requestData);

    // Step 3: Deserialize JSON data
    json_t *jsonObject;
    json_error_t error;
    jsonObject = json_loads(decodedData, 0, &error);

    // Step 4: Store deserialized data in variable and return it
    char *storedData = json_dumps(jsonObject, 0);
    printf("%s
", storedData);
    
    free(decodedData);
    free(storedData);

    return 0;
}