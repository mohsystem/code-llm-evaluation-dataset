public class Task5_GEMINI_gemini_1_5_pro_001 {
    public static int persistence(long num) {
        if (num < 10) {
            return 0;
        }
        int count = 0;
        while (num >= 10) {
            long prod = 1;
            while (num > 0) {
                prod *= (num % 10);
                num /= 10;
            }
            num = prod;
            count++;
        }
        return count;
    }

    public static void main(String[] args) {
        System.out.println(persistence(39));
        System.out.println(persistence(999));
        System.out.println(persistence(4));
    }
}