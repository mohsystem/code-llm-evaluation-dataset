#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void generateRandomString(int length, char* result) {
    const char letters[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    int lettersLength = strlen(letters);

    srand(time(0));

    for (int i = 0; i < length; i++) {
        int index = rand() % lettersLength;
        result[i] = letters[index];
    }

    result[length] = '\0';
}

int main() {
    int length = 10; // specify the length of the string
    char result[length + 1];
    generateRandomString(length, result);
    printf("%s\n", result);
    return 0;
}