// C code
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* caesarEncrypt(const char* text, int shift) {
    int len = strlen(text);
    char* result = (char*) malloc((len + 1) * sizeof(char));

    for (int i = 0; i < len; i++) {
        if ((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z')) {
            char base = (text[i] >= 'a' && text[i] <= 'z') ? 'a' : 'A';
            result[i] = (char) ((text[i] - base + shift) % 26 + base);
        } else {
            result[i] = text[i];
        }
    }

    result[len] = '\0';

    return result;
}

char* caesarDecrypt(const char* text, int shift) {
    int len = strlen(text);
    char* result = (char*) malloc((len + 1) * sizeof(char));

    for (int i = 0; i < len; i++) {
        if ((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z')) {
            char base = (text[i] >= 'a' && text[i] <= 'z') ? 'a' : 'A';
            result[i] = (char) ((text[i] - base - shift) % 26 + base);
        } else {
            result[i] = text[i];
        }
    }

    result[len] = '\0';

    return result;
}

void encryptFile(const char* filePath, int shift) {
    FILE* file = fopen(filePath, "r+");
    fseek(file, 0, SEEK_END);
    long len = ftell(file);
    rewind(file);

    char* text = (char*) malloc((len + 1) * sizeof(char));
    fread(text, 1, len, file);
    text[len] = '\0';

    char* encryptedText = caesarEncrypt(text, shift);

    fseek(file, 0, SEEK_SET);
    fwrite(encryptedText, 1, len, file);
    fclose(file);
    free(text);
    free(encryptedText);
}

void decryptFile(const char* filePath, int shift) {
    FILE* file = fopen(filePath, "r+");
    fseek(file, 0, SEEK_END);
    long len = ftell(file);
    rewind(file);

    char* text = (char*) malloc((len + 1) * sizeof(char));
    fread(text, 1, len, file);
    text[len] = '\0';

    char* decryptedText = caesarDecrypt(text, shift);

    fseek(file, 0, SEEK_SET);
    fwrite(decryptedText, 1, len, file);
    fclose(file);
    free(text);
    free(decryptedText);
}

int main() {
    const char* filePath = "example.txt";
    int shift = 3;
    encryptFile(filePath, shift);
    decryptFile(filePath, shift);
    return 0;
}