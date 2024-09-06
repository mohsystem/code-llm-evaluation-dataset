#include <vector>
using namespace std;
int findOutlier(std::vector<int> arr) {
  int parity = arr[0] % 2 + arr[1] % 2 + arr[2] % 2;
  if (parity < 2) {
    for (int i : arr) {
      if (i % 2 != 0) {
        return i;
      }
    }
  } else {
    for (int i : arr) {
      if (i % 2 == 0) {
        return i;
      }
    }
  }
  return 0;
}