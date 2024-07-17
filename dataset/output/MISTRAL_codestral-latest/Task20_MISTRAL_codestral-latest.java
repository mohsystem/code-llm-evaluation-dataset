// Java
public class Main {
    public static void main(String[] args) {
        System.out.println(digPow(89, 1));
        System.out.println(digPow(92, 1));
        System.out.println(digPow(695, 2));
        System.out.println(digPow(46288, 3));
    }

    public static int digPow(int n, int p) {
        int sum = 0;
        int temp = n;
        while (temp > 0) {
            sum += Math.pow(temp % 10, p++);
            temp /= 10;
        }
        return sum % n == 0 ? sum / n : -1;
    }
}