
public class Solution {
    public static int getSum(int a, int b) {
        if (a == b) {
            return a;
        }
        int start = Math.min(a, b);
        int end = Math.max(a, b);
        int sum = 0;
        for (int i = start; i <= end; i++) {
            sum += i;
        }
        return sum;
    }

    public static void main(String[] args) {
        System.out.println(getSum(1, 0));
        System.out.println(getSum(1, 2));
        System.out.println(getSum(0, 1));
        System.out.println(getSum(1, 1));
        System.out.println(getSum(-1, 0));
        System.out.println(getSum(-1, 2));
    }
}
