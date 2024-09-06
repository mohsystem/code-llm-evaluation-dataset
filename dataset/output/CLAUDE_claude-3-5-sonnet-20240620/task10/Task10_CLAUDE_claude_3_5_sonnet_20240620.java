
public class Task10_CLAUDE_claude_3_5_sonnet_20240620 {
    public int getSum(int a, int b) {
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
}
