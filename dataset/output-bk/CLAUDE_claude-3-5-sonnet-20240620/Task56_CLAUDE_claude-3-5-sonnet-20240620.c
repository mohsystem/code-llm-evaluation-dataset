
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TOKEN_LENGTH 32

char* generate_token() {
    static const char alphanum[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";
    char* token = malloc(TOKEN_LENGTH + 1);
    
    srand(time(NULL));
    for (int i = 0; i < TOKEN_LENGTH; ++i) {
        token[i] = alphanum[rand() % (sizeof(alphanum) - 1)];
    }
    token[TOKEN_LENGTH] = 0;
    
    return token;
}

int main() {
    char* token = generate_token();
    printf("Generated token: %s\
", token);
    free(token);
    return 0;
}
