import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;
import java.util.UUID;

public class Task56_PERPLEXITY_llama_3_sonar_large_32k_chat {
    public static String generateToken(String username, String password) {
        String timestamp = String.valueOf(System.currentTimeMillis());
        String tokenStr = username + password + timestamp;
        try {
            MessageDigest md = MessageDigest.getInstance("SHA-256");
            byte[] bytes = md.digest(tokenStr.getBytes());
            StringBuilder tokenHash = new StringBuilder();
            for (byte b : bytes) {
                tokenHash.append(String.format("%02x", b));
            }
            return tokenHash.toString();
        } catch (NoSuchAlgorithmException e) {
            throw new RuntimeException(e);
        }
    }

    public static void main(String[] args) {
        String username = "john";
        String password = "password123";
        System.out.println("Token: " + generateToken(username, password));
    }
}