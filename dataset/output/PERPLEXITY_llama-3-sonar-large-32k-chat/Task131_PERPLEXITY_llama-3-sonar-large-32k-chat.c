#include <stdio.h>
#include <string.h>

void deserializeData(const char* data) {
    char token[256];
    char* ptr = strtok((char*)data, ":");
    while (ptr != NULL) {
        printf("Deserialized data: %s\n", ptr);
        ptr = strtok(NULL, ":");
    }
}

int main() {
    printf("Enter serialized data (in key-value format, e.g., key1:value1:key2:value2): ");
    char data[256];
    fgets(data, sizeof(data), stdin);
    data[strcspn(data, "\n")] = 0; // remove newline character
    deserializeData(data);
    return 0;
}