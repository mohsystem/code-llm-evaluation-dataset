
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

char* generate_random_string(int length) {
    const char characters[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char* result = malloc((length + 1) * sizeof(char));
    
    srand(time(NULL));
    
    for (int i = 0; i < length; i++) {
        int random_index = rand() % (sizeof(characters) - 1);
        result[i] = characters[random_index];
    }
    
    result[length] = '\\0';
    return result;
}

int main() {
    char* random_string = generate_random_string(10);
    printf("%s\\n", random_string);
    free(random_string);
    return 0;
}
