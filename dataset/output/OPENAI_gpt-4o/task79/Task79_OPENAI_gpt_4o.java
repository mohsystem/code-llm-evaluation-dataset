import javax.crypto.Cipher;
import javax.crypto.KeyGenerator;
import javax.crypto.SecretKey;
import javax.crypto.spec.SecretKeySpec;
import java.util.Base64;

public class Task79_OPENAI_gpt_4o {
    public static String encrypt(String message, String secretKey) throws Exception {
        byte[] key = secretKey.getBytes("UTF-8");
        SecretKeySpec secretKeySpec = new SecretKeySpec(key, "AES");
        
        Cipher cipher = Cipher.getInstance("AES");
        cipher.init(Cipher.ENCRYPT_MODE, secretKeySpec);
        
        byte[] encryptedBytes = cipher.doFinal(message.getBytes("UTF-8"));
        return Base64.getEncoder().encodeToString(encryptedBytes);
    }

    public static void main(String[] args) {
        try {
            String message = "Secret Message";
            String secretKey = "thisisaverysecret";
            String encryptedMessage = encrypt(message, secretKey);
            System.out.println("Encrypted: " + encryptedMessage);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}