#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char *generateRandomString(int length) {
    char *str = malloc((length + 1) * sizeof(char));
    const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const int charsetSize = sizeof(charset) - 1;

    srand(time(NULL));
    for (int i = 0; i < length; i++) {
        int randomIndex = rand() % charsetSize;
        str[i] = charset[randomIndex];
    }
    str[length] = '\0';

    return str;
}

int main() {
    int length = 10; // Specify the desired length of the random string
    char *randomString = generateRandomString(length);
    printf("%s
", randomString);
    free(randomString);

    return 0;
}