public class Main {
    public static void main(String[] args) {
        System.out.println(digitPowerSum(89, 1));
        System.out.println(digitPowerSum(92, 1));
        System.out.println(digitPowerSum(695, 2));
        System.out.println(digitPowerSum(46288, 3));
    }

    public static int digitPowerSum(int n, int p) {
        String str = String.valueOf(n);
        long sum = 0;
        for (int i = 0; i < str.length(); i++) {
            sum += Math.pow(Character.getNumericValue(str.charAt(i)), p + i);
        }
        if (sum % n == 0) {
            return (int) (sum / n);
        } else {
            return -1;
        }
    }
}