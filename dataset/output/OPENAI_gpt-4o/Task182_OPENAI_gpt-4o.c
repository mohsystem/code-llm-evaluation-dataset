#include <stdio.h>
#include <string.h>
#include <ctype.h>

void cleanNumber(char* input, char* output) {
    int j = 0;
    for (int i = 0; i < strlen(input); i++) {
        if (isdigit(input[i])) {
            output[j] = input[i];
            j++;
        }
    }
    output[j] = '\0';

    if (output[0] == '1' && strlen(output) == 11) {
        for (int i = 1; i < 11; i++) {
            output[i-1] = output[i];
        }
        output[10] = '\0';
    }
}

int main() {
    char* numbers[] = {"+1 (613)-995-0253", "613-995-0253", "1 613 995 0253", "613.995.0253"};
    char cleanedNumbers[4][11];
    
    for (int i = 0; i < 4; i++) {
        cleanNumber(numbers[i], cleanedNumbers[i]);
        printf("%s\n", cleanedNumbers[i]);
    }

    return 0;
}