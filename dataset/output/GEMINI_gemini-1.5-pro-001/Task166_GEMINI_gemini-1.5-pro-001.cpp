#include <vector>
#include <algorithm>
using namespace std;

vector<int> posNegSort(vector<int> arr) {
  if (arr.empty()) {
    return arr;
  }
  vector<int> posList;
  for (int i = 0; i < arr.size(); i++) {
    if (arr[i] > 0) {
      posList.push_back(arr[i]);
    }
  }
  sort(posList.begin(), posList.end());
  int j = 0;
  for (int i = 0; i < arr.size(); i++) {
    if (arr[i] > 0) {
      arr[i] = posList[j++];
    }
  }
  return arr;
}