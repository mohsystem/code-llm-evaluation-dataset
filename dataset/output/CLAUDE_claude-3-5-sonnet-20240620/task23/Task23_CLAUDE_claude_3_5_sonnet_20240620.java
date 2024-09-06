
public class Task23_CLAUDE_claude_3_5_sonnet_20240620 {
    public static long findNb(long m) {
        long n = 1;
        long volume = 0;
        while (volume < m) {
            volume += n * n * n;
            if (volume == m) {
                return n;
            }
            n++;
        }
        return -1;
    }
}
