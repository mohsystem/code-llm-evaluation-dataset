
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* make_complement(const char* dna) {
    int len = strlen(dna);
    char* complement = (char*)malloc(len + 1);
    for (int i = 0; i < len; i++) {
        switch (dna[i]) {
            case \'A\':
                complement[i] = \'T\';
                break;
            case \'T\':
                complement[i] = \'A\';
                break;
            case \'C\':
                complement[i] = \'G\';
                break;
            case \'G\':
                complement[i] = \'C\';
                break;
        }
    }
    complement[len] = \'\\0\';
    return complement;
}

int main() {
    char* result1 = make_complement("ATTGC");
    printf("%s\
", result1); // Output: TAACG
    free(result1);

    char* result2 = make_complement("GTAT");
    printf("%s\
", result2); // Output: CATA
    free(result2);

    return 0;
}
