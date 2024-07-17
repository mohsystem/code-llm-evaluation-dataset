import java.security.SecureRandom;

public class RandomGenerator {

    public static void main(String[] args) {
        // Generate random number
        int randomNumber = generateRandomNumber(1, 10);
        System.out.println("Random number between 1 and 10: " + randomNumber);

        // Generate random token
        String randomToken = generateRandomToken(20);
        System.out.println("Random token of length 20: " + randomToken);
    }

    public static int generateRandomNumber(int min, int max) {
        SecureRandom random = new SecureRandom();
        return random.nextInt(max - min + 1) + min;
    }

    public static String generateRandomToken(int length) {
        String characters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
        SecureRandom random = new SecureRandom();
        StringBuilder token = new StringBuilder();

        for (int i = 0; i < length; i++) {
            int randomIndex = random.nextInt(characters.length());
            token.append(characters.charAt(randomIndex));
        }

        return token.toString();
    }
}