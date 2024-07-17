public class Solution {
    public boolean xorGame(int[] nums) {
        int xor = 0;
        for (int num : nums) {
            xor ^= num;
        }
        return nums.length % 2 == 1 && xor != 0;
    }
}