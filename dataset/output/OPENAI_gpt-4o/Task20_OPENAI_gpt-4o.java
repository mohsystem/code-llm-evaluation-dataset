public class FunnyProperties {
    public static int digPow(int n, int p) {
        String numStr = String.valueOf(n);
        int sum = 0;
        for (int i = 0; i < numStr.length(); i++) {
            sum += Math.pow(Character.getNumericValue(numStr.charAt(i)), p + i);
        }
        if (sum % n == 0) {
            return sum / n;
        } else {
            return -1;
        }
    }
    
    public static void main(String[] args) {
        System.out.println(digPow(89, 1));       // Output: 1
        System.out.println(digPow(92, 1));       // Output: -1
        System.out.println(digPow(695, 2));      // Output: 2
        System.out.println(digPow(46288, 3));    // Output: 51
    }
}