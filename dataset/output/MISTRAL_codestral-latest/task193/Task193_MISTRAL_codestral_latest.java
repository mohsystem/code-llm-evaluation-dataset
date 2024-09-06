public class Task193_MISTRAL_codestral_latest {
    public boolean xorGame(int[] nums) {
        int xor = 0;
        for (int num : nums) {
            xor ^= num;
        }
        return xor != 0 && nums.length % 2 == 1;
    }
}