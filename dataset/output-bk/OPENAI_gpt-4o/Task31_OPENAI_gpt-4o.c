#include <stdio.h>
#include <string.h>

void dna_complement(char* dna, char* result) {
    int len = strlen(dna);
    for (int i = 0; i < len; i++) {
        if (dna[i] == 'A') result[i] = 'T';
        else if (dna[i] == 'T') result[i] = 'A';
        else if (dna[i] == 'C') result[i] = 'G';
        else if (dna[i] == 'G') result[i] = 'C';
    }
    result[len] = '\0';
}

int main() {
    char* inputs[] = {"ATTGC", "GTAT"};
    for (int i = 0; i < 2; i++) {
        char result[100];
        dna_complement(inputs[i], result);
        printf("%s
", result);
    }
    return 0;
}