
public class Task20_CLAUDE_claude_3_5_sonnet_20240620 {
    public static long digPow(int n, int p) {
        long sum = 0;
        for (char c : String.valueOf(n).toCharArray()) {
            sum += Math.pow(Character.getNumericValue(c), p++);
        }
        return sum % n == 0 ? sum / n : -1;
    }
}
