#include <stdio.h>
#include <string.h>

void makeComplement(char *dna) {
    for (int i = 0; i < strlen(dna); i++) {
        switch (dna[i]) {
            case 'A':
                dna[i] = 'T';
                break;
            case 'T':
                dna[i] = 'A';
                break;
            case 'C':
                dna[i] = 'G';
                break;
            case 'G':
                dna[i] = 'C';
                break;
        }
    }
}