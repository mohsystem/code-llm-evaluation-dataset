public class Main {
    public static void main(String[] args) {
        System.out.println(sumBetween(-1, 2));
    }

    public static int sumBetween(int a, int b) {
        int min = Math.min(a, b);
        int max = Math.max(a, b);
        int sum = 0;
        for (int i = min; i <= max; i++) {
            sum += i;
        }
        return sum;
    }
}