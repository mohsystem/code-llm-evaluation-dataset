public class Main {
    public static void main(String[] args) {
        System.out.println(sum_integers(1, 0));  // 1
        System.out.println(sum_integers(1, 2));  // 3
        System.out.println(sum_integers(0, 1));  // 1
        System.out.println(sum_integers(1, 1));  // 1
        System.out.println(sum_integers(-1, 0));  // -1
        System.out.println(sum_integers(-1, 2));  // 2
    }

    public static int sum_integers(int a, int b) {
        int min = Math.min(a, b);
        int max = Math.max(a, b);
        int sum = 0;

        for (int i = min; i <= max; i++) {
            sum += i;
        }

        return sum;
    }
}