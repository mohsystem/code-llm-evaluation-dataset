// C
#include <stdio.h>
#include <string.h>

void reverse(char* start, char* end) {
    char temp;
    while (start < end) {
        temp = *start;
        *start++ = *end;
        *end-- = temp;
    }
}

void reverseWords(char* str) {
    char* word_begin = NULL;
    char* temp = str;
    while (*temp) {
        if ((word_begin == NULL) && ((*temp == ' ') || (*temp == '\0')))
            word_begin = temp;
        if ((word_begin != NULL) && (*(temp + 1) == ' ' || *(temp + 1) == '\0')) {
            if ((temp - word_begin) >= 4) {
                reverse(word_begin, temp);
            }
            word_begin = NULL;
        }
        temp++;
    }
}

int main() {
    char input[] = "Hey fellow warriors";
    reverseWords(input);
    printf("%s
", input);
    return 0;
}