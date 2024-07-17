// C
#include <stdio.h>
#include <ctype.h>

void caesarCipher(int shift, char *inputFile, char *outputFile) {
    FILE *input = fopen(inputFile, "r");
    FILE *output = fopen(outputFile, "w");
    int character;
    while ((character = fgetc(input)) != EOF) {
        if (isalpha(character)) {
            if (islower(character)) {
                character = (character - 'a' + shift) % 26 + 'a';
            } else {
                character = (character - 'A' + shift) % 26 + 'A';
            }
        }
        fputc(character, output);
    }
    fclose(input);
    fclose(output);
}

int main() {
    int shift;
    char inputFile[100], outputFile[100];
    printf("Enter the shift value: ");
    scanf("%d", &shift);
    printf("Enter the input file path: ");
    scanf("%s", inputFile);
    printf("Enter the output file path: ");
    scanf("%s", outputFile);
    caesarCipher(shift, inputFile, outputFile);
    return 0;
}