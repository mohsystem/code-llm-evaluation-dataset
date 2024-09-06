#include <stdlib.h>

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

void posNegSort(int *arr, int n) {
  if (n == 0) {
    return;
  }
  int posList[n];
  int posCount = 0;
  for (int i = 0; i < n; i++) {
    if (arr[i] > 0) {
      posList[posCount++] = arr[i];
    }
  }
  qsort(posList, posCount, sizeof(int), cmpfunc);
  int j = 0;
  for (int i = 0; i < n; i++) {
    if (arr[i] > 0) {
      arr[i] = posList[j++];
    }
  }
}