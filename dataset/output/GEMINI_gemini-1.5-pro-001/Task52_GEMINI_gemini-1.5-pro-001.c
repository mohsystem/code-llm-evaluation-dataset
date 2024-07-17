//  Encryption and decryption in C are more complex and typically require external libraries. 
//  This example focuses on illustrating a basic XOR encryption for demonstration purposes.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encryptDecrypt(char *input, char *output, char *key) {
    int i = 0;
    int keylen = strlen(key);
    while (*input) {
        *output = *input ^ key[i % keylen]; 
        input++;
        output++;
        i++;
    }
    *output = '\0'; 
}

int main() {
    FILE *inputFile, *outputFile;
    char filename[100], key[100], ch;
    int choice;

    printf("Enter filename: ");
    scanf("%s", filename);

    printf("Enter encryption key: ");
    scanf("%s", key);

    // Create a copy of the filename for the encrypted/decrypted file
    char outputFilename[100];
    strcpy(outputFilename, filename);
    strcat(outputFilename, ".enc"); // Append .enc for encrypted

    // Encryption
    inputFile = fopen(filename, "r");
    if (inputFile == NULL) {
        printf("Error opening input file.
");
        return 1;
    }

    outputFile = fopen(outputFilename, "w");
    if (outputFile == NULL) {
        printf("Error opening output file.
");
        fclose(inputFile);
        return 1;
    }

    while ((ch = fgetc(inputFile)) != EOF) {
        char encryptedChar = ch ^ key[ftell(inputFile) % strlen(key)]; 
        fputc(encryptedChar, outputFile);
    }
    fclose(inputFile);
    fclose(outputFile);

    printf("File encrypted successfully.
");

    // Decryption (for demonstration - you'd usually separate these)
    inputFile = fopen(outputFilename, "r");
    if (inputFile == NULL) {
        printf("Error opening encrypted file.
");
        return 1;
    }

    strcpy(outputFilename, filename); // Reset output filename
    strcat(outputFilename, ".dec"); // Append .dec for decrypted

    outputFile = fopen(outputFilename, "w");
    if (outputFile == NULL) {
        printf("Error opening decrypted file.
");
        fclose(inputFile);
        return 1;
    }

    while ((ch = fgetc(inputFile)) != EOF) {
        char decryptedChar = ch ^ key[ftell(inputFile) % strlen(key)];
        fputc(decryptedChar, outputFile);
    }

    fclose(inputFile);
    fclose(outputFile);

    printf("File decrypted successfully.
");

    return 0;
}