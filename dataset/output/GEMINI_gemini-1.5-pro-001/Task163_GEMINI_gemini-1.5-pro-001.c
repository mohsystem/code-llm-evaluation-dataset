#include <stdio.h>
#include <stdlib.h>

int longestRun(int arr[], int arr_size) {
  if (arr_size <= 1) {
    return arr_size;
  }

  int maxRun = 1;
  int currentRun = 1;

  for (int i = 1; i < arr_size; i++) {
    if (arr[i] == arr[i - 1] + 1 || arr[i] == arr[i - 1] - 1) {
      currentRun++;
    } else {
      currentRun = 1;
    }

    if (currentRun > maxRun) {
      maxRun = currentRun;
    }
  }

  return maxRun;
}

int main() {
  int arr1[] = {1, 2, 3, 5, 6, 7, 8, 9};
  int arr2[] = {1, 2, 3, 10, 11, 15};
  int arr3[] = {5, 4, 2, 1};
  int arr4[] = {3, 5, 7, 10, 15};

  int size1 = sizeof(arr1) / sizeof(arr1[0]);
  int size2 = sizeof(arr2) / sizeof(arr2[0]);
  int size3 = sizeof(arr3) / sizeof(arr3[0]);
  int size4 = sizeof(arr4) / sizeof(arr4[0]);

  printf("%d\n", longestRun(arr1, size1)); // Output: 5
  printf("%d\n", longestRun(arr2, size2)); // Output: 3
  printf("%d\n", longestRun(arr3, size3)); // Output: 2
  printf("%d\n", longestRun(arr4, size4)); // Output: 1

  return 0;
}