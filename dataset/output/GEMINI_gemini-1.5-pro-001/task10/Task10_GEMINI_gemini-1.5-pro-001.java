class Solution {
    public int getSum(int a, int b) {
        if (a == b) {
            return a;
        } else {
            int sum = 0;
            for (int i = Math.min(a, b); i <= Math.max(a, b); i++) {
                sum += i;
            }
            return sum;
        }
    }
}