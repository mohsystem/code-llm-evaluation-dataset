import javax.crypto.Cipher;
import javax.crypto.spec.IvParameterSpec;
import javax.crypto.spec.SecretKeySpec;
import java.security.SecureRandom;
import java.util.Base64;

public class EncryptData {

    private static final byte[] IV = new byte[] { 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f };

    public static void main(String[] args) throws Exception {
        String keyString = "YourSecretKeyHere"; // Replace with your actual secret key
        String data = "This is some data to encrypt.";

        byte[] encryptedData = encrypt(keyString, data);
        String base64EncodedData = Base64.getEncoder().encodeToString(encryptedData);

        System.out.println(base64EncodedData);
    }

    public static byte[] encrypt(String keyString, String data) throws Exception {
        SecretKeySpec key = new SecretKeySpec(keyString.getBytes(), "AES");
        IvParameterSpec iv = new IvParameterSpec(IV);
        Cipher cipher = Cipher.getInstance("AES/CBC/PKCS5Padding");
        cipher.init(Cipher.ENCRYPT_MODE, key, iv);

        return cipher.doFinal(data.getBytes());
    }
}