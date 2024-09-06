#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int binary_search(int arr[], int target, int low, int high) {
  while (low <= high) {
    int mid = (low + high) / 2;
    if (arr[mid] == target) {
      return mid;
    } else if (arr[mid] < target) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }

  return -1;
}

int main() {
  // Generate a random array of 100,000 integers
  int arr[100000];
  for (int i = 0; i < 100000; i++) {
    arr[i] = rand() % 100000;
  }

  // Generate a random target element
  int target = rand() % 100000;

  // Start the timer
  clock_t start = clock();

  // Perform the binary search
  int result = binary_search(arr, target, 0, 99999);

  // Stop the timer
  clock_t end = clock();

  // Calculate the execution time
  double execution_time = (double)(end - start) / CLOCKS_PER_SEC;

  // Write the execution time to a file
  FILE *file = fopen("execution_time.txt", "w");
  fprintf(file, "%f", execution_time);
  fclose(file);

  return 0;
}