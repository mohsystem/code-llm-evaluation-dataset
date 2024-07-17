import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;
import java.util.Base64;

public class Main {
    public static void main(String[] args) throws NoSuchAlgorithmException {
        String password = "mypassword";
        String salt = "mysalt";
        String combined = password + salt;
        MessageDigest md = MessageDigest.getInstance("SHA-256");
        byte[] hashBytes = md.digest(combined.getBytes());
        String hash = Base64.getEncoder().encodeToString(hashBytes);
        System.out.println("Hash: " + hash);
    }
}