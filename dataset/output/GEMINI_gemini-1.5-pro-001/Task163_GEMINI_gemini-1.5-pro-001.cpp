#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int longestRun(vector<int> arr) {
  if (arr.size() <= 1) {
    return arr.size();
  }

  int maxRun = 1;
  int currentRun = 1;

  for (size_t i = 1; i < arr.size(); i++) {
    if (arr[i] == arr[i - 1] + 1 || arr[i] == arr[i - 1] - 1) {
      currentRun++;
    } else {
      currentRun = 1;
    }

    maxRun = max(maxRun, currentRun);
  }

  return maxRun;
}

int main() {
  vector<int> arr1 = {1, 2, 3, 5, 6, 7, 8, 9};
  vector<int> arr2 = {1, 2, 3, 10, 11, 15};
  vector<int> arr3 = {5, 4, 2, 1};
  vector<int> arr4 = {3, 5, 7, 10, 15};

  cout << longestRun(arr1) << endl; // Output: 5
  cout << longestRun(arr2) << endl; // Output: 3
  cout << longestRun(arr3) << endl; // Output: 2
  cout << longestRun(arr4) << endl; // Output: 1

  return 0;
}