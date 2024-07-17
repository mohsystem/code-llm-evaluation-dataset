import java.security.SecureRandom;

public class RandomString {

    public static void main(String[] args) {
        int length = 10; // Specify the desired length of the random string
        String randomString = generateRandomString(length);
        System.out.println(randomString);
    }

    public static String generateRandomString(int length) {
        SecureRandom random = new SecureRandom();
        StringBuilder sb = new StringBuilder(length);

        for (int i = 0; i < length; i++) {
            int randomIndex = random.nextInt(52); // 26 letters (a-z) + 26 letters (A-Z) = 52
            char randomChar = (char) (randomIndex < 26 ? randomIndex + 'a' : randomIndex - 26 + 'A');
            sb.append(randomChar);
        }

        return sb.toString();
    }
}