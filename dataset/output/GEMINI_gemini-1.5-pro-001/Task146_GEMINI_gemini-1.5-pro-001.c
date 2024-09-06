#include <stdio.h>

int findMissingNumber(int arr[], int n) {
  int expectedSum = (n + 1) * (n + 2) / 2;
  int actualSum = 0;
  for (int i = 0; i < n; i++) {
    actualSum += arr[i];
  }
  return expectedSum - actualSum;
}