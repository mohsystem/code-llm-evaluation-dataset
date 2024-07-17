
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void reverse(char* start, char* end) {
    char temp;
    while (start < end) {
        temp = *start;
        *start++ = *end;
        *end-- = temp;
    }
}

char* spinWords(const char* sentence) {
    char* result = strdup(sentence);
    char* word = strtok(result, " ");
    
    while (word != NULL) {
        if (strlen(word) >= 5) {
            reverse(word, word + strlen(word) - 1);
        }
        word = strtok(NULL, " ");
    }
    
    return result;
}

int main() {
    printf("%s\
", spinWords("Hey fellow warriors"));
    printf("%s\
", spinWords("This is a test"));
    printf("%s\
", spinWords("This is another test"));
    return 0;
}
