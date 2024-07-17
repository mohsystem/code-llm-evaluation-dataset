
import javax.crypto.Cipher;
import javax.crypto.spec.IvParameterSpec;
import javax.crypto.spec.SecretKeySpec;
import java.util.Base64;

public class AESEncryption {
    public static void main(String[] args) throws Exception {
        String key = "ThisIsASecretKey";
        String initVector = "RandomInitVector";
        String plaintext = "TextToBeEncrypted";

        IvParameterSpec iv = new IvParameterSpec(initVector.getBytes("UTF-8"));
        SecretKeySpec skeySpec = new SecretKeySpec(key.getBytes("UTF-8"), "AES");

        Cipher cipher = Cipher.getInstance("AES/CBC/PKCS5PADDING");
        cipher.init(Cipher.ENCRYPT_MODE, skeySpec, iv);

        byte[] encrypted = cipher.doFinal(plaintext.getBytes());
        System.out.println(Base64.getEncoder().encodeToString(encrypted));
    }
}
