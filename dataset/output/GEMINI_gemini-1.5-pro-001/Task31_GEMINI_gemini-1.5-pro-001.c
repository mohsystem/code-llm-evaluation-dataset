#include <string.h>
#include <stdlib.h>

char *DNA_strand(const char *dna) {
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
    }
  }
  complement[len] = '\0';
  return complement;
}