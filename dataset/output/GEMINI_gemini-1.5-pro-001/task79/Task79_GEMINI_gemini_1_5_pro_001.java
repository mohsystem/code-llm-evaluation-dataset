import javax.crypto.Cipher;
import javax.crypto.KeyGenerator;
import javax.crypto.SecretKey;
import javax.crypto.spec.SecretKeySpec;
import java.util.Base64;

public class Task79_GEMINI_gemini_1_5_pro_001 {

    public static String encryptMessage(String message, String secretKey) throws Exception {
        // Convert the secret key from string to bytes
        byte[] decodedKey = Base64.getDecoder().decode(secretKey);
        SecretKey originalKey = new SecretKeySpec(decodedKey, 0, decodedKey.length, "AES");

        // Create the cipher
        Cipher cipher = Cipher.getInstance("AES");
        cipher.init(Cipher.ENCRYPT_MODE, originalKey);

        // Encrypt the message
        byte[] encryptedMessage = cipher.doFinal(message.getBytes());

        // Return the encrypted message as a Base64 encoded string
        return Base64.getEncoder().encodeToString(encryptedMessage);
    }
}