import javax.crypto.Cipher;
import javax.crypto.KeyGenerator;
import javax.crypto.SecretKey;
import java.util.Base64;

public class Encryption {
    public static void main(String[] args) throws Exception {
        String message = "This is a secret message";
        String encryptedMessage = encrypt(message);
        System.out.println("Encrypted: " + encryptedMessage);
    }

    public static String encrypt(String message) throws Exception {
        // Generate a secret key
        KeyGenerator keyGenerator = KeyGenerator.getInstance("AES");
        keyGenerator.init(128); // Specify key size
        SecretKey secretKey = keyGenerator.generateKey();

        // Create a cipher object
        Cipher cipher = Cipher.getInstance("AES");
        cipher.init(Cipher.ENCRYPT_MODE, secretKey);

        // Encrypt the message
        byte[] encryptedBytes = cipher.doFinal(message.getBytes());

        // Encode the encrypted bytes to Base64
        return Base64.getEncoder().encodeToString(encryptedBytes);
    }
}