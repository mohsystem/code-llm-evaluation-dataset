
#include <string.h>
#include <stdlib.h>

char *dna_strand(const char *dna)
{
    int len = strlen(dna);
    char *result = malloc(len + 1);
    for (int i = 0; i < len; i++) {
        switch(dna[i]) {
            case 'A': result[i] = 'T'; break;
            case 'T': result[i] = 'A'; break;
            case 'C': result[i] = 'G'; break;
            case 'G': result[i] = 'C'; break;
        }
    }
    result[len] = '\\0';
    return result;
}
