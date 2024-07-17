public class Solution {
    public int rand7() {
        return (int) (Math.random() * 7) + 1;
    }

    public int rand10() {
        while (true) {
            int num = (rand7() - 1) * 7 + rand7();
            if (num <= 40) {
                return num % 10 + 1;
            }
        }
    }

    public int[] main(int n) {
        int[] result = new int[n];
        for (int i = 0; i < n; i++) {
            result[i] = rand10();
        }
        return result;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        int n = 1;  // change this to test with different inputs
        int[] result = solution.main(n);
        for (int num : result) {
            System.out.print(num + " ");
        }
    }
}