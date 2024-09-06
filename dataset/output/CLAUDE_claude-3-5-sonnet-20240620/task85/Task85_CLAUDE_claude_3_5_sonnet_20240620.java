
import java.util.Random;

public class Task85_CLAUDE_claude_3_5_sonnet_20240620 {
    public static String generateRandomString(int length) {
        String characters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
        StringBuilder result = new StringBuilder(length);
        Random random = new Random();
        
        for (int i = 0; i < length; i++) {
            result.append(characters.charAt(random.nextInt(characters.length())));
        }
        
        return result.toString();
    }

    public static void main(String[] args) {
        System.out.println(generateRandomString(10));
    }
}
