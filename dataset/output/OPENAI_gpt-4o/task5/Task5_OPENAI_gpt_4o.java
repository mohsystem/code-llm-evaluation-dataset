public class Task5_OPENAI_gpt_4o {
    public static int persistence(int num) {
        int count = 0;
        while (num >= 10) {
            num = multiplyDigits(num);
            count += 1;
        }
        return count;
    }

    private static int multiplyDigits(int num) {
        int result = 1;
        while (num > 0) {
            result *= num % 10;
            num /= 10;
        }
        return result;
    }

    public static void main(String[] args) {
        System.out.println(persistence(39));  // 3
        System.out.println(persistence(999)); // 4
        System.out.println(persistence(4));   // 0
    }
}