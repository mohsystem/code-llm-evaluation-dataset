#include <stdio.h>
#include <math.h>

int binary_array_to_number(int arr[], int size) {
  int decimal = 0;
  for (int i = 0; i < size; i++) {
    decimal += arr[i] * pow(2, size - i - 1);
  }
  return decimal;
}

int main() {
  int arr1[] = {0, 0, 0, 1};
  int arr2[] = {0, 0, 1, 0};
  int arr3[] = {0, 1, 0, 1};
  int arr4[] = {1, 0, 0, 1};
  int arr5[] = {0, 0, 1, 0};
  int arr6[] = {0, 1, 1, 0};
  int arr7[] = {1, 1, 1, 1};
  int arr8[] = {1, 0, 1, 1};

  printf("%d\n", binary_array_to_number(arr1, 4)); // Output: 1
  printf("%d\n", binary_array_to_number(arr2, 4)); // Output: 2
  printf("%d\n", binary_array_to_number(arr3, 4)); // Output: 5
  printf("%d\n", binary_array_to_number(arr4, 4)); // Output: 9
  printf("%d\n", binary_array_to_number(arr5, 4)); // Output: 2
  printf("%d\n", binary_array_to_number(arr6, 4)); // Output: 6
  printf("%d\n", binary_array_to_number(arr7, 4)); // Output: 15
  printf("%d\n", binary_array_to_number(arr8, 4)); // Output: 11

  return 0;
}