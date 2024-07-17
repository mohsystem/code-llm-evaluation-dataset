
#include <stdio.h>
#include <stdlib.h>

#define KEY 0x42

void encrypt_decrypt(const char* input_file, const char* output_file) {
    FILE *fin, *fout;
    int ch;

    fin = fopen(input_file, "rb");
    if (fin == NULL) {
        printf("Error opening input file.\
");
        exit(1);
    }

    fout = fopen(output_file, "wb");
    if (fout == NULL) {
        printf("Error opening output file.\
");
        fclose(fin);
        exit(1);
    }

    while ((ch = fgetc(fin)) != EOF) {
        fputc(ch ^ KEY, fout);
    }

    fclose(fin);
    fclose(fout);
}

int main() {
    char choice;
    char input_file[100], output_file[100];

    printf("Enter \'e\' to encrypt or \'d\' to decrypt: ");
    scanf(" %c", &choice);
    printf("Enter input file name: ");
    scanf("%s", input_file);
    printf("Enter output file name: ");
    scanf("%s", output_file);

    encrypt_decrypt(input_file, output_file);
    printf("Operation completed successfully.\
");

    return 0;
}
