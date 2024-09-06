#include <iostream>
#include <vector>
#include <time.h>
#include <fstream>

using namespace std;

int binary_search(vector<int>& arr, int target) {
  int low = 0;
  int high = arr.size() - 1;

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
  vector<int> arr;
  for (int i = 0; i < 100000; i++) {
    arr.push_back(rand() % 100000);
  }

  // Generate a random target element
  int target = rand() % 100000;

  // Start the timer
  clock_t start = clock();

  // Perform the binary search
  int result = binary_search(arr, target);

  // Stop the timer
  clock_t end = clock();

  // Calculate the execution time
  double execution_time = (double)(end - start) / CLOCKS_PER_SEC;

  // Write the execution time to a file
  ofstream file("execution_time.txt");
  file << execution_time;

  return 0;
}