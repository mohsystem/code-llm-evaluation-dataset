#include <stdio.h>
#include <stdlib.h>

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

void sort_array(int *arr, int n) {
  qsort(arr, n, sizeof(int), cmpfunc);
}