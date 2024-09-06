import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;

public class Task82_PERPLEXITY_llama_3_sonar_large_32k_chat {
    public static String computeHash(String password, String salt) throws NoSuchAlgorithmException {
        String combined = password + salt;
        MessageDigest md = MessageDigest.getInstance("SHA-256");
        byte[] bytes = md.digest(combined.getBytes());
        StringBuilder sb = new StringBuilder();
        for (byte b : bytes) {
            sb.append(String.format("%02x", b));
        }
        return sb.toString();
    }

    public static void main(String[] args) throws NoSuchAlgorithmException {
        String password = "mysecretpassword";
        String salt = "mysalt";
        System.out.println(computeHash(password, salt));
    }
}