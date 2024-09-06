import java.util.Arrays;

public class Task193_OPENAI_gpt_4o {
    public static boolean xorGame(int[] nums) {
        int xorValue = 0;
        for (int num : nums) {
            xorValue ^= num;
        }
        return xorValue == 0 || nums.length % 2 == 0;
    }

    public static void main(String[] args) {
        System.out.println(xorGame(new int[]{1, 1, 2}));  // Output: false
        System.out.println(xorGame(new int[]{0, 1}));    // Output: true
        System.out.println(xorGame(new int[]{1, 2, 3})); // Output: true
    }
}