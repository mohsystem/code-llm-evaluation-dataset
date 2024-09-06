import java.util.Random;

public class Task85_MISTRAL_codestral_latest {
    public static void main(String[] args) {
        int length = 10; // specify the length of the string
        System.out.println(generateRandomString(length));
    }

    public static String generateRandomString(int length) {
        String letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
        StringBuilder sb = new StringBuilder();
        Random random = new Random();

        for (int i = 0; i < length; i++) {
            int index = random.nextInt(letters.length());
            sb.append(letters.charAt(index));
        }

        return sb.toString();
    }
}