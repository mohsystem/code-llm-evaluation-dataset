public class NarcissisticNumber {
    public static boolean isNarcissistic(int number) {
        int originalNumber, result = 0, remainder;
        int n = Integer.toString(number).length();

        originalNumber = number;

        while (originalNumber != 0) {
            remainder = originalNumber % 10;
            result += Math.pow(remainder, n);
            originalNumber /= 10;
        }

        return number == result;
    }
}