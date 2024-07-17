#include <stdio.h>
#include <string.h>

char* DNATranslate(char* dna) {
    char* complement = malloc((strlen(dna) + 1) * sizeof(char));
    for (int i = 0; i < strlen(dna); i++) {
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
    complement[strlen(dna)] = '\0';
    return complement;
}

int main() {
    char dna1[] = "ATTGC";
    char dna2[] = "GTAT";
    char* complement1 = DNATranslate(dna1);
    char* complement2 = DNATranslate(dna2);
    printf("%s --> %s
", dna1, complement1); // --> "TAACG"
    printf("%s --> %s
", dna2, complement2); // --> "CATA"
    free(complement1);
    free(complement2);
    return 0;
}