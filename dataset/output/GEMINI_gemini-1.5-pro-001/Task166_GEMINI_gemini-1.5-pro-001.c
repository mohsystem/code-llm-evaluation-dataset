#include <stdio.h>
#include <stdlib.h>

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

int * posNegSort(int * arr, int arr_size) {
  if (arr_size == 0) {
    return arr;
  }
  int pos_size = 0;
  for (int i = 0; i < arr_size; i++) {
    if (arr[i] > 0) {
      pos_size++;
    }
  }
  int * pos = (int *)malloc(pos_size * sizeof(int));
  int j = 0;
  for (int i = 0; i < arr_size; i++) {
    if (arr[i] > 0) {
      pos[j++] = arr[i];
    }
  }
  qsort(pos, pos_size, sizeof(int), cmpfunc);
  j = 0;
  int * result = (int *)malloc(arr_size * sizeof(int));
  for (int i = 0; i < arr_size; i++) {
    if (arr[i] > 0) {
      result[i] = pos[j++];
    } else {
      result[i] = arr[i];
    }
  }
  free(pos);
  return result;
}