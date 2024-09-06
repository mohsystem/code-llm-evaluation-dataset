import java.nio.charset.StandardCharsets;
import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;

public class Task82_OPENAI_gpt_4o {
    public static void main(String[] args) throws NoSuchAlgorithmException {
        String password = "example_password";
        String salt = "random_salt";
        System.out.println("Java Hash: " + computeHash(password, salt));
    }

    public static String computeHash(String password, String salt) throws NoSuchAlgorithmException {
        String combined = password + salt;
        MessageDigest digest = MessageDigest.getInstance("SHA-256");
        byte[] encodedhash = digest.digest(combined.getBytes(StandardCharsets.UTF_8));
        StringBuilder hexString = new StringBuilder(2 * encodedhash.length);
        for (byte b : encodedhash) {
            String hex = Integer.toHexString(0xff & b);
            if (hex.length() == 1) {
                hexString.append('0');
            }
            hexString.append(hex);
        }
        return hexString.toString();
    }
}