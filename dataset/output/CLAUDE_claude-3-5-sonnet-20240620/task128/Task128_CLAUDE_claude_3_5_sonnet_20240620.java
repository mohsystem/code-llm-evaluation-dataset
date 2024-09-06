
import java.util.Random;

public class Task128_CLAUDE_claude_3_5_sonnet_20240620 {
    private static final String CHARACTERS = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    private static final Random random = new Random();

    public static int generateRandomNumber(int minVal, int maxVal) {
        return random.nextInt(maxVal - minVal + 1) + minVal;
    }

    public static String generateRandomToken(int length) {
        StringBuilder token = new StringBuilder(length);
        for (int i = 0; i < length; i++) {
            token.append(CHARACTERS.charAt(random.nextInt(CHARACTERS.length())));
        }
        return token.toString();
    }

    public static void main(String[] args) {
        System.out.println("Random number: " + generateRandomNumber(1, 100));
        System.out.println("Random token: " + generateRandomToken(10));
    }
}
