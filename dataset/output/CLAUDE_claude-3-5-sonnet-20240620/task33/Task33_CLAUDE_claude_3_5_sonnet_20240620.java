
public class Task33_CLAUDE_claude_3_5_sonnet_20240620 {
    public static int queueTime(int[] customers, int n) {
        int[] tills = new int[n];
        for (int customer : customers) {
            tills[0] += customer;
            java.util.Arrays.sort(tills);
        }
        return tills[n - 1];
    }
}
