
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define TOKEN_LENGTH 32

char* generate_token() {
    const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    char* token = malloc(TOKEN_LENGTH + 1);
    
    srand(time(NULL));
    
    for (int i = 0; i < TOKEN_LENGTH; i++) {
        int index = rand() % (sizeof(charset) - 1);
        token[i] = charset[index];
    }
    
    token[TOKEN_LENGTH] = '\\0';
    return token;
}

int main() {
    char* auth_token = generate_token();
    printf("Generated authentication token: %s\\n", auth_token);
    free(auth_token);
    return 0;
}
