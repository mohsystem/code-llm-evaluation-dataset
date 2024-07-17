
import javax.crypto.Cipher;
import javax.crypto.spec.SecretKeySpec;
import java.util.Base64;

public class MessageEncryption {
    public static void main(String[] args) throws Exception {
        String message = "Hello, World!";
        String secretKey = "MySecretKey12345";

        String encryptedMessage = encrypt(message, secretKey);
        System.out.println("Encrypted message: " + encryptedMessage);
    }

    public static String encrypt(String message, String secretKey) throws Exception {
        SecretKeySpec key = new SecretKeySpec(secretKey.getBytes(), "AES");
        Cipher cipher = Cipher.getInstance("AES");
        cipher.init(Cipher.ENCRYPT_MODE, key);
        byte[] encryptedBytes = cipher.doFinal(message.getBytes());
        return Base64.getEncoder().encodeToString(encryptedBytes);
    }
}
