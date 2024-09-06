public class Task34_MISTRAL_codestral_latest {
    public static boolean isNarcissistic(int number) {
        int originalNumber, result = 0, n = 0;

        originalNumber = number;

        while (originalNumber != 0) {
            originalNumber /= 10;
            ++n;
        }

        originalNumber = number;

        while (originalNumber != 0) {
            int remainder = originalNumber % 10;
            result += Math.pow(remainder, n);
            originalNumber /= 10;
        }

        return number == result;
    }
}