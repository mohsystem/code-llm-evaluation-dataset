import java.util.Random;
class Solution {
    public int rand10() {
        while (true) {
            int row = rand7();
            int col = rand7();
            int idx = col + (row - 1) * 7;
            if (idx <= 40) {
                return 1 + (idx - 1) % 10;
            }
        }
    }
    private int rand7() {
        Random rand = new Random();
        return rand.nextInt(7) + 1;
    }
}