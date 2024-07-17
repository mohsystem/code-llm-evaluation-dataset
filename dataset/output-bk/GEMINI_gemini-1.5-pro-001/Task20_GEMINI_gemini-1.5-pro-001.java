class Solution {
    public static long digPow(long n, long p) {
        String str = String.valueOf(n);
        long sum = 0;
        for (int i = 0; i < str.length(); i++, p++) {
            int digit = Integer.parseInt(String.valueOf(str.charAt(i)));
            sum += Math.pow(digit, p);
        }
        return (sum % n == 0) ? sum / n : -1;
    }

    public static void main(String[] args) {
        System.out.println(digPow(89, 1));
        System.out.println(digPow(92, 1));
        System.out.println(digPow(695, 2));
        System.out.println(digPow(46288, 3));
    }
}