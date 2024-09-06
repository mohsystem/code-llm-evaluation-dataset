import javax.crypto.Cipher;
import javax.crypto.spec.IvParameterSpec;
import javax.crypto.spec.SecretKeySpec;
import java.security.Key;
import java.util.Base64;

public class Task72_PERPLEXITY_llama_3_sonar_large_32k_chat {
    public static void main(String[] args) throws Exception {
        String plainText = "Hello, World!";
        byte[] iv = new byte[16];  // static IV
        Key key = new SecretKeySpec("your_secret_key_here".getBytes(), "AES");
        Cipher cipher = Cipher.getInstance("AES/CBC/PKCS5Padding");
        cipher.init(Cipher.ENCRYPT_MODE, key, new IvParameterSpec(iv));
        byte[] encryptedData = cipher.doFinal(plainText.getBytes());
        System.out.println(Base64.getEncoder().encodeToString(encryptedData));
    }
}