// C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define STRING_LENGTH 10

char* generate_random_string(int length) {
    char* str = malloc(sizeof(char) * (length + 1));
    const char characters[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    for (int i = 0; i < length; i++) {
        str[i] = characters[rand() % (sizeof(characters) - 1)];
    }
    str[length] = '\0';
    return str;
}

int main() {
    srand(time(0));
    char* randomString = generate_random_string(STRING_LENGTH);
    char* tempFileName = tmpnam(NULL);
    FILE* tempFile = fopen(tempFileName, "w");
    fwrite(randomString, sizeof(char), STRING_LENGTH, tempFile);
    fclose(tempFile);
    printf("%s
", tempFileName);
    free(randomString);
    return 0;
}