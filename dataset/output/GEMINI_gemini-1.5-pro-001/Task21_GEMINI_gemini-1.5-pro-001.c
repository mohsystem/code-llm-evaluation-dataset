#include <stdio.h>
#include <stdlib.h>

int find_min_index(int arr[], int n) {
  if (n == 0) {
    return -1; // Handle empty array case
  }
  int min_index = 0;
  for (int i = 1; i < n; i++) {
    if (arr[i] < arr[min_index]) {
      min_index = i;
    }
  }
  return min_index;
}

int* remove_element(int arr[], int n, int index) {
  if (index < 0 || index >= n) {
    return arr; // Invalid index, return original array
  }
  int *new_arr = (int*)malloc((n - 1) * sizeof(int));
  for (int i = 0, j = 0; i < n; i++) {
    if (i != index) {
      new_arr[j++] = arr[i];
    }
  }
  return new_arr;
}

int main() {
  int numbers1[] = {1, 2, 3, 4, 5};
  int n1 = sizeof(numbers1) / sizeof(numbers1[0]);
  int min_index1 = find_min_index(numbers1, n1);
  int *result1 = remove_element(numbers1, n1, min_index1);
  for (int i = 0; i < n1 - 1; i++) {
    printf("%d ", result1[i]);
  }
  printf("\n");
  free(result1); 

  int numbers2[] = {5, 3, 2, 1, 4};
  int n2 = sizeof(numbers2) / sizeof(numbers2[0]);
  int min_index2 = find_min_index(numbers2, n2);
  int *result2 = remove_element(numbers2, n2, min_index2);
  for (int i = 0; i < n2 - 1; i++) {
    printf("%d ", result2[i]);
  }
  printf("\n");
  free(result2);

  int numbers3[] = {2, 2, 1, 2, 1};
  int n3 = sizeof(numbers3) / sizeof(numbers3[0]);
  int min_index3 = find_min_index(numbers3, n3);
  int *result3 = remove_element(numbers3, n3, min_index3);
  for (int i = 0; i < n3 - 1; i++) {
    printf("%d ", result3[i]);
  }
  printf("\n");
  free(result3);

  return 0;
}