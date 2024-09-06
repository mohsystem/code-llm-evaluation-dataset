
import java.security.SecureRandom;
import java.util.Base64;

public class Task56_CLAUDE_claude_3_5_sonnet_20240620 {
    private static final SecureRandom secureRandom = new SecureRandom();

    public static String generateToken() {
        byte[] randomBytes = new byte[24];
        secureRandom.nextBytes(randomBytes);
        return Base64.getUrlEncoder().withoutPadding().encodeToString(randomBytes);
    }

    public static void main(String[] args) {
        String authToken = generateToken();
        System.out.println("Generated authentication token: " + authToken);
    }
}
