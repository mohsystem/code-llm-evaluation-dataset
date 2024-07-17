public class Main {
    public static void main(String[] args) {
        System.out.println(persistence(39)); // should return 3
        System.out.println(persistence(999)); // should return 4
        System.out.println(persistence(4)); // should return 0
    }

    public static int persistence(int num) {
        int count = 0;
        while (num >= 10) {
            num = multiplyDigits(num);
            count++;
        }
        return count;
    }

    private static int multiplyDigits(int num) {
        int product = 1;
        while (num > 0) {
            product *= num % 10;
            num /= 10;
        }
        return product;
    }
}