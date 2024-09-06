#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <jansson.h>
#include <libbase64.h>

// Function to process the request
char* process_request(const char* req);

// Example usage
int main() {
    json_t *data = json_pack("{s:s}", "key", "value");
    char *json_str = json_dumps(data, 0);
    
    size_t base64_len;
    char *encoded_data = (char*) malloc(strlen(json_str) * 2); // Ensure sufficient space
    
    base64_encode(json_str, strlen(json_str), encoded_data, &base64_len, 0);
    
    char *result = process_request(encoded_data);
    
    printf("%s\n", result);
    
    free(encoded_data);
    free(result);
    json_decref(data);
    free(json_str);
    
    return 0;
}

char* process_request(const char* req) {
    // Step 1: Retrieve the raw_data from the request, ensuring it is encoded in UTF-8

    // Step 2: Decode the raw_data using Base64
    size_t decode_len = strlen(req);
    char *decoded_data = (char*) malloc(decode_len);
    size_t outlen;
    base64_decode(req, decode_len, decoded_data, &outlen, 0);
    
    // Null-terminate the decoded string
    decoded_data[outlen] = '\0';

    // Step 3: Deserialize the decoded data into its original format (e.g., JSON)
    json_error_t error;
    json_t *deserialized_data = json_loads(decoded_data, 0, &error);
    if (!deserialized_data) {
        printf("error: on line %d: %s\n", error.line, error.text);
        free(decoded_data);
        return NULL;
    }
    
    // Step 4: Store the deserialized data in a variable
    json_t *stored_data = deserialized_data;
    
    // Serialize JSON back to string for return
    char *stored_data_str = json_dumps(stored_data, 0);
    
    // Step 5: Return the stored data
    json_decref(stored_data);
    free(decoded_data);
    return stored_data_str;
}