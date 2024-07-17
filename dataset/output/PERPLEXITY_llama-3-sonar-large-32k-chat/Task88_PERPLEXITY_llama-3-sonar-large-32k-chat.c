#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define RAND_STRING_LENGTH 10
#define TEMP_FILE_NAME "tempXXXXXX.txt"

char* generateRandomString() {
    char* chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    char* randomString = malloc(RAND_STRING_LENGTH + 1);
    srand(time(NULL));
    for (int i = 0; i < RAND_STRING_LENGTH; i++) {
        randomString[i] = chars[rand() % strlen(chars)];
    }
    randomString[RAND_STRING_LENGTH] = '\0';
    return randomString;
}

char* toUnicode(char* str) {
    char* unicodeString = malloc(strlen(str) * 6 + 1);
    char* p = unicodeString;
    for (char* q = str; *q; q++) {
        sprintf(p, "\\u%04x", (unsigned int)*q);
        p += 6;
    }
    *p = '\0';
    return unicodeString;
}

void writeToFile(char* filePath, char* content) {
    FILE* file = fopen(filePath, "w");
    fprintf(file, "%s", content);
    fclose(file);
}

int main() {
    char template[] = TEMP_FILE_NAME;
    FILE* tempFile = tmpfile();
    if (tempFile == NULL) {
        perror("tmpfile");
        return 1;
    }
    fclose(tempFile);
    char* filePath = strdup(template);
    for (char* p = filePath; *p; p++) {
        if (*p == 'X') {
            *p = 'A' + rand() % 26;
        }
    }
    char* randomString = generateRandomString();
    char* unicodeString = toUnicode(randomString);
    writeToFile(filePath, unicodeString);
    printf("%s
", filePath);
    free(randomString);
    free(unicodeString);
    free(filePath);
    return 0;
}