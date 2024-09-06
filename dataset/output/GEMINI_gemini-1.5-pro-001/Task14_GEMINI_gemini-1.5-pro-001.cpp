#include <vector>
using namespace std;
int find_even_index (const vector<int> numbers) {
  for (int i = 0; i < numbers.size(); i++) {
    int leftSum = 0;
    for (int j = 0; j < i; j++) {
      leftSum += numbers[j];
    }
    int rightSum = 0;
    for (int j = i + 1; j < numbers.size(); j++) {
      rightSum += numbers[j];
    }
    if (leftSum == rightSum) {
      return i;
    }
  }
  return -1;
}