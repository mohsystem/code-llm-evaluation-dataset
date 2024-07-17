#include <vector>
#include <algorithm>
using namespace std;

vector<int> posNegSort(vector<int> arr) {
  if (arr.empty()) {
    return arr;
  }
  vector<int> pos;
  for (int num : arr) {
    if (num > 0) {
      pos.push_back(num);
    }
  }
  sort(pos.begin(), pos.end());
  int j = 0;
  vector<int> result(arr.size());
  for (int i = 0; i < arr.size(); i++) {
    if (arr[i] > 0) {
      result[i] = pos[j++];
    } else {
      result[i] = arr[i];
    }
  }
  return result;
}