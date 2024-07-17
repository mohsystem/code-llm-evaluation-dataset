#include <iostream>
#include <vector>

using namespace std;

vector<int> mergeSortedArrays(vector<int> &arr1, vector<int> &arr2) {
  vector<int> merged;
  int i = 0;
  int j = 0;
  while (i < arr1.size() && j < arr2.size()) {
    if (arr1[i] < arr2[j]) {
      merged.push_back(arr1[i]);
      i++;
    } else {
      merged.push_back(arr2[j]);
      j++;
    }
  }
  while (i < arr1.size()) {
    merged.push_back(arr1[i]);
    i++;
  }
  while (j < arr2.size()) {
    merged.push_back(arr2[j]);
    j++;
  }
  return merged;
}

int main() {
  vector<int> arr1 = {1, 3, 5, 7};
  vector<int> arr2 = {2, 4, 6, 8};
  vector<int> mergedArray = mergeSortedArrays(arr1, arr2);
  for (int num : mergedArray) {
    cout << num << " ";
  }
  cout << endl;
  return 0;
}