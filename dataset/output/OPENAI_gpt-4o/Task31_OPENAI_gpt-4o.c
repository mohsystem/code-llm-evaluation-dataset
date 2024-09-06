#include <stdio.h>
#include <string.h>

void dnaStrand(const char* dna, char* complement) {
    int i;
    for (i = 0; dna[i] != '\0'; i++) {
        switch (dna[i]) {
            case 'A':
                complement[i] = 'T';
                break;
            case 'T':
                complement[i] = 'A';
                break;
            case 'C':
                complement[i] = 'G';
                break;
            case 'G':
                complement[i] = 'C';
                break;
        }
    }
    complement[i] = '\0';
}

int main() {
    char dna1[] = "ATTGC";
    char dna2[] = "GTAT";
    char complement1[6], complement2[5];

    dnaStrand(dna1, complement1);
    dnaStrand(dna2, complement2);

    printf("%s\n", complement1);  // Output: TAACG
    printf("%s\n", complement2);  // Output: CATA

    return 0;
}