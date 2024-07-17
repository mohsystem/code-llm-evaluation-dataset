// Java
import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;
import java.security.SecureRandom;
import java.util.Base64;

public class PasswordHash {
    public static void main(String[] args) throws NoSuchAlgorithmException {
        String password = "your_password";
        byte[] salt = getSalt();
        String hashedPassword = getSecurePassword(password, salt);
        System.out.println(hashedPassword);
    }

    private static byte[] getSalt() throws NoSuchAlgorithmException {
        SecureRandom sr = SecureRandom.getInstance("SHA1PRNG");
        byte[] salt = new byte[16];
        sr.nextBytes(salt);
        return salt;
    }

    private static String getSecurePassword(String password, byte[] salt) throws NoSuchAlgorithmException {
        String algorithm = "SHA-256";
        int iterationNb = 10000;
        int keyLength = 256;
        MessageDigest md = MessageDigest.getInstance(algorithm);
        md.reset();
        md.update(salt);
        byte[] hashedPassword = md.digest(password.getBytes());
        for (int i = 0; i < iterationNb; i++) {
            md.reset();
            hashedPassword = md.digest(hashedPassword);
        }
        return Base64.getEncoder().encodeToString(hashedPassword);
    }
}