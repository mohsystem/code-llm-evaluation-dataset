public class XORGame {
    public static boolean xorGame(int[] nums) {
        int xor_sum = 0;
        for (int num : nums) {
            xor_sum ^= num;
        }
        return xor_sum == 0 || nums.length % 2 == 0;
    }

    public static void main(String[] args) {
        int[] nums1 = {1, 1, 2};
        System.out.println(xorGame(nums1)); // Output: false

        int[] nums2 = {0, 1};
        System.out.println(xorGame(nums2)); // Output: true

        int[] nums3 = {1, 2, 3};
        System.out.println(xorGame(nums3)); // Output: true
    }
}