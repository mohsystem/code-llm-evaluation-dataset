public class Task174_OPENAI_gpt_4o {
    public static void main(String[] args) {
        String s = "aacecaaa";
        System.out.println(shortestPalindrome(s));
    }

    public static String shortestPalindrome(String s) {
        String rev_s = new StringBuilder(s).reverse().toString();
        for (int i = 0; i <= s.length(); i++) {
            if (s.startsWith(rev_s.substring(i))) {
                return rev_s.substring(0, i) + s;
            }
        }
        return "";
    }
}