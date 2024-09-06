public class Task10_OPENAI_gpt_4o {
    public static int getSum(int a, int b) {
        if (a == b) return a;
        if (a > b) {
            int temp = a;
            a = b;
            b = temp;
        }
        int sum = 0;
        for (int i = a; i <= b; i++) {
            sum += i;
        }
        return sum;
    }

    public static void main(String[] args) {
        int result = getSum(1, 0); // Example usage
        System.out.println(result);
    }
}