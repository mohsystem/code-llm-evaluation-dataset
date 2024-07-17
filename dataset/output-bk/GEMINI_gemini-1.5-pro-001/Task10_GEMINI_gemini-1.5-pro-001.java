class Solution {
    public int getSum(int a, int b) {
        return (a == b) ? a : (a + b) * (Math.abs(a - b) + 1) / 2;
    }
}