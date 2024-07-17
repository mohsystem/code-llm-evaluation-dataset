
public class DigPow {
    public static long digPow(int n, int p) {
        String digits = String.valueOf(n);
        long sum = 0;
        for (int i = 0; i < digits.length(); i++) {
            int digit = Character.getNumericValue(digits.charAt(i));
            sum += Math.pow(digit, p + i);
        }
        if (sum % n == 0) {
            return sum / n;
        }
        return -1;
    }

    public static void main(String[] args) {
        System.out.println(digPow(89, 1));
        System.out.println(digPow(92, 1));
        System.out.println(digPow(695, 2));
        System.out.println(digPow(46288, 3));
    }
}
