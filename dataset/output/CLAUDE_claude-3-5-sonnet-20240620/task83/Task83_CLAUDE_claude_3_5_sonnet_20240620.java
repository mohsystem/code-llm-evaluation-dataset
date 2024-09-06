
import javax.crypto.Cipher;
import javax.crypto.spec.IvParameterSpec;
import javax.crypto.spec.SecretKeySpec;
import java.security.SecureRandom;
import java.util.Base64;

public class Task83_CLAUDE_claude_3_5_sonnet_20240620 {
    public static String encryptKey(String key) throws Exception {
        byte[] iv = new byte[16];
        new SecureRandom().nextBytes(iv);
        IvParameterSpec ivspec = new IvParameterSpec(iv);

        SecretKeySpec secretKey = new SecretKeySpec(SecureRandom.getInstanceStrong().generateSeed(32), "AES");

        Cipher cipher = Cipher.getInstance("AES/CBC/PKCS5Padding");
        cipher.init(Cipher.ENCRYPT_MODE, secretKey, ivspec);

        byte[] encrypted = cipher.doFinal(key.getBytes("UTF-8"));
        byte[] encryptedIVAndText = new byte[iv.length + encrypted.length];
        System.arraycopy(iv, 0, encryptedIVAndText, 0, iv.length);
        System.arraycopy(encrypted, 0, encryptedIVAndText, iv.length, encrypted.length);

        return Base64.getEncoder().encodeToString(encryptedIVAndText);
    }

    public static void main(String[] args) throws Exception {
        String keyToEncrypt = "MySecretKey123456";
        String encryptedKey = encryptKey(keyToEncrypt);
        System.out.println("Encrypted key: " + encryptedKey);
    }
}
