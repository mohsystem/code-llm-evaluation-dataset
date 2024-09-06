
import javax.crypto.Cipher;
import javax.crypto.spec.IvParameterSpec;
import javax.crypto.spec.SecretKeySpec;
import java.security.SecureRandom;
import java.util.Arrays;

public class Task72_CLAUDE_claude_3_5_sonnet_20240620 {
    public static byte[] encryptData(byte[] data, byte[] key) throws Exception {
        // Create a static initialization vector (IV)
        byte[] iv = new byte[16];
        Arrays.fill(iv, (byte) 0);

        // Initialize a cipher using AES in CBC mode with the static IV
        Cipher cipher = Cipher.getInstance("AES/CBC/PKCS5Padding");
        SecretKeySpec secretKeySpec = new SecretKeySpec(key, "AES");
        IvParameterSpec ivParameterSpec = new IvParameterSpec(iv);
        cipher.init(Cipher.ENCRYPT_MODE, secretKeySpec, ivParameterSpec);

        // Encrypt the data using the cipher (padding is handled automatically)
        return cipher.doFinal(data);
    }

    public static void main(String[] args) throws Exception {
        byte[] key = new byte[32];
        new SecureRandom().nextBytes(key);
        byte[] data = "This is a secret message.".getBytes();
        byte[] encrypted = encryptData(data, key);
        System.out.println(Arrays.toString(encrypted));
    }
}
