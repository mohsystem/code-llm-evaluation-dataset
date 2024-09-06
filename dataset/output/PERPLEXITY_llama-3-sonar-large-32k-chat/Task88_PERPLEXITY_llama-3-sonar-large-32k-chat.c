#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char* getRandomString() {
    char* SALTCHARS = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    char* salt = (char*)malloc(11 * sizeof(char));
    srand(time(0));
    for (int i = 0; i < 10; i++) {
        salt[i] = SALTCHARS[rand() % strlen(SALTCHARS)];
    }
    salt[10] = '\0';
    return salt;
}

char* toUnicode(const char* str) {
    char* unicodeString = (char*)malloc((strlen(str) * 6 + 1) * sizeof(char));
    char* p = unicodeString;
    for (; *str; str++) {
        sprintf(p, "\\u%04x", *str);
        p += 6;
    }
    *p = '\0';
    return unicodeString;
}

int main() {
    char* randomString = getRandomString();
    char* unicodeString = toUnicode(randomString);
    char tempFileName[256];
    sprintf(tempFileName, "temp_%s.txt", getRandomString());
    FILE* tempFile = fopen(tempFileName, "wb");
    fwrite(unicodeString, strlen(unicodeString), 1, tempFile);
    fclose(tempFile);
    printf("%s\n", tempFileName);
    free(randomString);
    free(unicodeString);
    return 0;
}