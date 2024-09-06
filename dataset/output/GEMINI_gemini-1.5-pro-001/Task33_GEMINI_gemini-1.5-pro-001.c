#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
  return (*(int *)a - *(int *)b);
}

int queueTime(int *customers, int customers_length, int n) {
  if (customers_length == 0) {
    return 0;
  }
  
  if (n == 1) {
    int total_time = 0;
    for (int i = 0; i < customers_length; i++) {
      total_time += customers[i];
    }
    return total_time;
  }

  if (n >= customers_length) {
    int max_time = customers[0];
    for (int i = 1; i < customers_length; i++) {
      if (customers[i] > max_time) {
        max_time = customers[i];
      }
    }
    return max_time;
  }

  int *tills = (int *)malloc(n * sizeof(int));
  for (int i = 0; i < n; i++) {
    tills[i] = 0;
  }

  for (int i = 0; i < customers_length; i++) {
    int min_index = 0;
    for (int j = 1; j < n; j++) {
      if (tills[j] < tills[min_index]) {
        min_index = j;
      }
    }
    tills[min_index] += customers[i];
  }

  qsort(tills, n, sizeof(int), compare);
  int result = tills[n - 1];
  free(tills);
  return result;
}