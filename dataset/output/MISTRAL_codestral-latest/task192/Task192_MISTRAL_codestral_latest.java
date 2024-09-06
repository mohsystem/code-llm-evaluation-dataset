public class Task192_MISTRAL_codestral_latest {
    public boolean xorGame(int[] nums) {
        int xor = 0;
        for (int num : nums) {
            xor ^= num;
        }

        if (xor == 0) {
            return false;
        } else if (nums.length % 2 == 0) {
            return false;
        } else {
            return true;
        }
    }
}