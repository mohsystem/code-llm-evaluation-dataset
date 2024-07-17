#include <stdio.h>
#include <string.h>

void deserializeData(const char* data) {
    printf("Deserialized data: %s
", data);
}

int main() {
    printf("Enter serialized data: ");
    char data[1024];
    fgets(data, 1024, stdin);
    data[strcspn(data, "
")] = 0; // remove newline character
    deserializeData(data);
    return 0;
}