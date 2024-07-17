#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int longestRun(vector<int> nums) {
  if (nums.size() <= 1) {
    return nums.size();
  }
  int longest = 1;
  int current = 1;
  for (int i = 1; i < nums.size(); i++) {
    if (nums[i] == nums[i - 1] + 1 || nums[i] == nums[i - 1] - 1) {
      current++;
    } else {
      current = 1;
    }
    longest = max(longest, current);
  }
  return longest;
}