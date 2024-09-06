
import java.io.FileOutputStream;
import java.io.IOException;
import java.security.NoSuchAlgorithmException;
import java.security.SecureRandom;
import java.security.spec.InvalidKeySpecException;
import java.util.Scanner;
import javax.crypto.SecretKeyFactory;
import javax.crypto.spec.PBEKeySpec;

public class Task122_CLAUDE_claude_3_5_sonnet_20240620 {
    public static void main(String[] args) {
        signup();
    }

    public static void signup() {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter username: ");
        String username = scanner.nextLine();
        System.out.print("Enter password: ");
        String password = scanner.nextLine();

        try {
            byte[] hashedPassword = hashPassword(password);
            storePassword(username, hashedPassword);
            System.out.println("Signup successful!");
        } catch (Exception e) {
            System.out.println("An error occurred during signup: " + e.getMessage());
        }
    }

    private static byte[] hashPassword(String password) throws NoSuchAlgorithmException, InvalidKeySpecException {
        SecureRandom random = new SecureRandom();
        byte[] salt = new byte[16];
        random.nextBytes(salt);

        PBEKeySpec spec = new PBEKeySpec(password.toCharArray(), salt, 65536, 128);
        SecretKeyFactory factory = SecretKeyFactory.getInstance("PBKDF2WithHmacSHA1");
        byte[] hash = factory.generateSecret(spec).getEncoded();

        byte[] combined = new byte[salt.length + hash.length];
        System.arraycopy(salt, 0, combined, 0, salt.length);
        System.arraycopy(hash, 0, combined, salt.length, hash.length);

        return combined;
    }

    private static void storePassword(String username, byte[] hashedPassword) throws IOException {
        try (FileOutputStream fos = new FileOutputStream("passwords.txt", true)) {
            fos.write((username + ":").getBytes());
            fos.write(hashedPassword);
            fos.write("\\n".getBytes());
        }
    }
}
