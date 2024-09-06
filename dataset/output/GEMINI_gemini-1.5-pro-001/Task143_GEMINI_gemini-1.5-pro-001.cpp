#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
  vector<int> inputArray = {5, 2, 9, 1, 5, 6};
  sort(inputArray.begin(), inputArray.end());
  for (int i = 0; i < inputArray.size(); i++) {
    cout << inputArray[i] << " ";
  }
  cout << endl;
  return 0;
}