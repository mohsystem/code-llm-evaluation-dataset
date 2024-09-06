
public class Task58_CLAUDE_claude_3_5_sonnet_20240620 {
    public static boolean getXO(String str) {
        str = str.toLowerCase();
        return str.replace("o", "").length() == str.replace("x", "").length();
    }
}
