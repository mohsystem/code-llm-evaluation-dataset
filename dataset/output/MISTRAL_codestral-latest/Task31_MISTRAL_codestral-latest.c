#include <string.h>
#include <stdlib.h>

char* DNAStrand(const char* dna) {
    int length = strlen(dna);
    char* complement = malloc(length + 1);
    for (int i = 0; i < length; i++) {
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
    complement[length] = '\0';
    return complement;
}