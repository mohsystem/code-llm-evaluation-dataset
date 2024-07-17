#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char* generate_token(int length) {
    char* token = malloc((length + 1) * sizeof(char));
    const char characters[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    const int characters_len = strlen(characters);

    srand(time(NULL));
    for (int i = 0; i < length; i++) {
        token[i] = characters[rand() % characters_len];
    }
    token[length] = '\0';
    return token;
}

int main() {
    char* token = generate_token(32);
    printf("%s
", token);
    free(token);
    return 0;
}