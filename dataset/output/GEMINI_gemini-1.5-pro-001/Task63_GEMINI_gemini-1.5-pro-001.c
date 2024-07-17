#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <b64/cdecode.h>

// Function to decode Base64 string
char* b64_decode(const char *src, size_t len) {
    base64_decodestate state;
    base64_init_decodestate(&state);

    // Calculate the maximum output buffer size
    size_t out_len = len * 3 / 4 + 1;
    char *out = (char*)malloc(out_len);
    if (out == NULL) {
        return NULL;
    }

    // Decode the input string
    int result = base64_decode_block(src, len, out, &state);
    out[result] = '\0'; // Null-terminate the output string

    return out;
}

// Function to process the request
char* processRequest(const char *rawData) {
    // Decode the raw_data using Base64
    char *decodedData = b64_decode(rawData, strlen(rawData));

    // Deserialize the decoded data
    // ... Implementation for deserialization (replace with your logic)

    return decodedData;
}

int main() {
    // Example usage:
    const char rawData[] = "eyJtZXNzYWdlIjogIkhlbGxvIHdvcmxkIn0=";
    char *processedData = processRequest(rawData);
    printf("%s
", processedData);

    free(processedData);
    return 0;
}