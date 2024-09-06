#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int binary_array_to_number(vector<int> arr) {
  int decimal = 0;
  for (int i = 0; i < arr.size(); i++) {
    decimal += arr[i] * pow(2, arr.size() - i - 1);
  }
  return decimal;
}

int main() {
  vector<int> arr1 = {0, 0, 0, 1};
  vector<int> arr2 = {0, 0, 1, 0};
  vector<int> arr3 = {0, 1, 0, 1};
  vector<int> arr4 = {1, 0, 0, 1};
  vector<int> arr5 = {0, 0, 1, 0};
  vector<int> arr6 = {0, 1, 1, 0};
  vector<int> arr7 = {1, 1, 1, 1};
  vector<int> arr8 = {1, 0, 1, 1};

  cout << binary_array_to_number(arr1) << endl; // Output: 1
  cout << binary_array_to_number(arr2) << endl; // Output: 2
  cout << binary_array_to_number(arr3) << endl; // Output: 5
  cout << binary_array_to_number(arr4) << endl; // Output: 9
  cout << binary_array_to_number(arr5) << endl; // Output: 2
  cout << binary_array_to_number(arr6) << endl; // Output: 6
  cout << binary_array_to_number(arr7) << endl; // Output: 15
  cout << binary_array_to_number(arr8) << endl; // Output: 11

  return 0;
}