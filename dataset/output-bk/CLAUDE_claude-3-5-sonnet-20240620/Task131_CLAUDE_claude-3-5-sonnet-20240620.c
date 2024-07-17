
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_SIZE 1024

unsigned char* base64_decode(const char* input, size_t* output_length) {
    const char base64_chars[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
    size_t input_length = strlen(input);
    unsigned char* decoded = malloc(input_length * 3 / 4);
    *output_length = 0;

    int val = 0, valb = -8;
    for (size_t i = 0; i < input_length; i++) {
        char c = input[i];
        if (c == \'=\') break;
        const char* p = strchr(base64_chars, c);
        if (p == NULL) continue;
        val = (val << 6) + (p - base64_chars);
        valb += 6;
        if (valb >= 0) {
            decoded[(*output_length)++] = (val >> valb) & 0xFF;
            valb -= 8;
        }
    }

    return decoded;
}

int main() {
    char serialized_data[MAX_INPUT_SIZE];
    printf("Enter the serialized data: ");
    fgets(serialized_data, sizeof(serialized_data), stdin);
    serialized_data[strcspn(serialized_data, "\
")] = 0;

    size_t decoded_length;
    unsigned char* decoded_data = base64_decode(serialized_data, &decoded_length);

    if (decoded_data) {
        printf("Deserialized data: ");
        for (size_t i = 0; i < decoded_length; i++) {
            printf("%c", decoded_data[i]);
        }
        printf("\
");
        free(decoded_data);
    } else {
        printf("Error: Invalid input or deserialization failed.\
");
    }

    return 0;
}
