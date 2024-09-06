public class Task20_MISTRAL_codestral_latest {
    public static int digPow(int n, int p) {
        String s = String.valueOf(n);
        int sum = 0;
        for (int i = 0; i < s.length(); i++) {
            sum += Math.pow(Character.getNumericValue(s.charAt(i)), p + i);
        }
        return sum % n == 0 ? sum / n : -1;
    }
}