import java.util.Base64;
import javax.crypto.Cipher;
import javax.crypto.KeyGenerator;
import javax.crypto.SecretKey;
import javax.crypto.spec.SecretKeySpec;

public class Main {
    public static void main(String[] args) throws Exception {
        // Generate a secret key
        KeyGenerator keyGen = KeyGenerator.getInstance("AES");
        keyGen.init(128);
        SecretKey secretKey = keyGen.generateKey();

        // Message to encrypt
        String message = "Hello, World!";

        // Create cipher
        Cipher cipher = Cipher.getInstance("AES");

        // Initialize cipher for encryption
        cipher.init(Cipher.ENCRYPT_MODE, secretKey);

        // Encrypt message
        byte[] encryptedMessage = cipher.doFinal(message.getBytes());
        String encodedMessage = Base64.getEncoder().encodeToString(encryptedMessage);

        System.out.println("Encrypted Message (Java): " + encodedMessage);
    }
}