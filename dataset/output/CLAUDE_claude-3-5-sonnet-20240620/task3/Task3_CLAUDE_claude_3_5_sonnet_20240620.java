
public class Task3_CLAUDE_claude_3_5_sonnet_20240620 {
    public static boolean isPangram(String str) {
        str = str.toLowerCase();
        for (char c = 'a'; c <= 'z'; c++) {
            if (str.indexOf(c) == -1) {
                return false;
            }
        }
        return true;
    }

    public static void main(String[] args) {
        String test = "The quick brown fox jumps over the lazy dog";
        System.out.println(isPangram(test));
    }
}
