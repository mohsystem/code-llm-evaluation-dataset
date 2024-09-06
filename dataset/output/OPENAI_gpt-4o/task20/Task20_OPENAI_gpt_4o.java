public class Task20_OPENAI_gpt_4o {
    public static void main(String[] args) {
        System.out.println(digPow(89, 1));     // Output: 1
        System.out.println(digPow(92, 1));     // Output: -1
        System.out.println(digPow(695, 2));    // Output: 2
        System.out.println(digPow(46288, 3));  // Output: 51
    }

    public static int digPow(int n, int p) {
        String digits = String.valueOf(n);
        int sum = 0;
        for (int i = 0; i < digits.length(); i++) {
            sum += Math.pow(Character.getNumericValue(digits.charAt(i)), p + i);
        }
        return sum % n == 0 ? sum / n : -1;
    }
}