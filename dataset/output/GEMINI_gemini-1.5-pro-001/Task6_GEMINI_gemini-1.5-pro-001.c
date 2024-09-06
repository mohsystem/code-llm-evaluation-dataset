#include <stdio.h>

double findUniq(double arr[], size_t n) {
  // Sort the array in ascending order
  for (size_t i = 0; i < n - 1; i++) {
    for (size_t j = i + 1; j < n; j++) {
      if (arr[i] > arr[j]) {
        double temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
      }
    }
  }
  // Find the unique element
  if (arr[0] != arr[1]) {
    return arr[0];
  } else {
    return arr[n - 1];
  }
}