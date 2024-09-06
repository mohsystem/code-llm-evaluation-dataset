#include <string.h>

char* dnaStrand(char* dna) {
    char* complement = (char*)malloc((strlen(dna) + 1) * sizeof(char));
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