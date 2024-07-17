#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *makeComplement(char *dna) {
    size_t len = strlen(dna);
    char *complement = malloc(len + 1); 
    if (complement == NULL) {
        return NULL; 
    }
    for (size_t i = 0; i < len; i++) {
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
            default:
                complement[i] = '?';
        }
    }
    complement[len] = '\0';
    return complement;
}

int main() {
    char dnaStrand[100];
    printf("Enter DNA strand: ");
    scanf("%s", dnaStrand);

    char *complement = makeComplement(dnaStrand);
    if (complement != NULL) {
        printf("%s
", complement);
        free(complement); 
    } else {
        printf("Memory allocation error!
");
    }
    return 0;
}