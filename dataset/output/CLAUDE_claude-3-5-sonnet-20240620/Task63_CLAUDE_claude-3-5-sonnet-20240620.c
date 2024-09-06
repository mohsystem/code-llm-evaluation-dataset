
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/bio.h>
#include <openssl/evp.h>
#include <jansson.h>

json_t* process_request(const char* raw_data) {
    // Ensure raw_data is UTF-8 encoded (assuming it's already UTF-8 in C)
    
    // Decode the raw_data using Base64
    BIO *b64, *bmem;
    char *decoded_data;
    int decoded_length;
    
    b64 = BIO_new(BIO_f_base64());
    bmem = BIO_new_mem_buf(raw_data, -1);
    bmem = BIO_push(b64, bmem);
    
    decoded_data = malloc(strlen(raw_data));
    decoded_length = BIO_read(bmem, decoded_data, strlen(raw_data));
    
    BIO_free_all(bmem);
    
    // Deserialize the decoded data (assuming JSON in this example)
    json_error_t error;
    json_t* deserialized_data = json_loads(decoded_data, 0, &error);
    
    // Store the deserialized data in a variable
    json_t* stored_data = deserialized_data;
    
    // Free the decoded data
    free(decoded_data);
    
    // Return the stored data
    return stored_data;
}

int main() {
    const char* raw_input = "eyJuYW1lIjogIkpvaG4gRG9lIiwgImFnZSI6IDMwfQ==";
    json_t* result = process_request(raw_input);
    char* json_str = json_dumps(result, JSON_INDENT(2));
    printf("%s\\n", json_str);
    free(json_str);
    json_decref(result);
    return 0;
}
