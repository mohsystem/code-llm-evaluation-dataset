
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_LENGTH 1000

void shuffle(char *array, int n, unsigned int seed) {
    srand(seed);
    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        char temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
}

void encrypt_message(const char *message, char *encrypted, int key) {
    char cipher[26];
    for (int i = 0; i < 26; i++) {
        cipher[i] = 'A' + i;
    }
    
    shuffle(cipher, 26, key);
    
    int i = 0;
    while (message[i] != '\\0') {
        if (isalpha(message[i])) {
            int index = toupper(message[i]) - 'A';
            encrypted[i] = cipher[index];
        } else {
            encrypted[i] = message[i];
        }
        i++;
    }
    encrypted[i] = '\\0';
}

int main() {
    char message[MAX_LENGTH] = "Hello, World!";
    char encrypted[MAX_LENGTH];
    int key = 42;
    
    encrypt_message(message, encrypted, key);
    
    printf("Original: %s\\n", message);
    printf("Encrypted: %s\\n", encrypted);
    
    return 0;
}
