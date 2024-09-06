#include <stdio.h>
#include <string.h>

void reverse(char *begin, char *end) {
    char temp;
    while (begin < end) {
        temp = *begin;
        *begin++ = *end;
        *end-- = temp;
    }
}

void spinWords(char *sentence) {
    char *word_begin = sentence;
    char *temp = sentence;
    
    while (*temp) {
        temp++;
        if (*temp == ' ' || *temp == '\0') {
            if (temp - word_begin >= 5) {
                reverse(word_begin, temp - 1);
            }
            word_begin = temp + 1;
        }
    }
}

void printExamples() {
    char examples[][100] = {"Hey fellow warriors", "This is a test", "This is another test"};
    for (int i = 0; i < 3; i++) {
        spinWords(examples[i]);
        printf("%s\n", examples[i]);
    }
}

int main() {
    printExamples();
    return 0;
}