public class Task172_MISTRAL_codestral_latest {
    public static boolean repeatedSubstringPattern(String s) {
        int n = s.length();
        for (int i = 1; i <= n / 2; i++) {
            if (n % i == 0 && s.substring(0, i).repeat(n / i).equals(s)) {
                return true;
            }
        }
        return false;
    }

    public static int numDistinct(String text) {
        int n = text.length();
        int count = 0;
        for (int i = 1; i <= n / 2; i++) {
            if (repeatedSubstringPattern(text.substring(0, i))) {
                count++;
            }
        }
        return count;
    }

    public static void main(String[] args) {
        String text = "abcabcabc";
        System.out.println(numDistinct(text));
    }
}