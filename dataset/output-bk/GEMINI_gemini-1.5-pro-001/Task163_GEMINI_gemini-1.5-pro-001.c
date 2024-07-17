#include <stdio.h>
#include <stdlib.h>

int longestRun(int nums[], int numsSize) {
  if (numsSize <= 1) {
    return numsSize;
  }
  int longest = 1;
  int current = 1;
  for (int i = 1; i < numsSize; i++) {
    if (nums[i] == nums[i - 1] + 1 || nums[i] == nums[i - 1] - 1) {
      current++;
    } else {
      current = 1;
    }
    if (current > longest) {
      longest = current;
    }
  }
  return longest;
}