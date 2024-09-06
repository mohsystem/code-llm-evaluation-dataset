#include <stdio.h>
#include <stdlib.h>

int cmpfunc(const void *a, const void *b) {
  return (*(int *)a - *(int *)b);
}

int main() {
  int inputArray[] = {5, 2, 9, 1, 5, 6};
  int n = sizeof(inputArray) / sizeof(inputArray[0]);
  qsort(inputArray, n, sizeof(int), cmpfunc);
  for (int i = 0; i < n; i++) {
    printf("%d ", inputArray[i]);
  }
  printf("\n");
  return 0;
}