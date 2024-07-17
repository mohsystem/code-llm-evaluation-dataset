class Solution {
  public static int longestRun(int[] nums) {
    if (nums.length <= 1) {
      return nums.length;
    }
    int longest = 1;
    int current = 1;
    for (int i = 1; i < nums.length; i++) {
      if (nums[i] == nums[i - 1] + 1 || nums[i] == nums[i - 1] - 1) {
        current++;
      } else {
        current = 1;
      }
      longest = Math.max(longest, current);
    }
    return longest;
  }
}