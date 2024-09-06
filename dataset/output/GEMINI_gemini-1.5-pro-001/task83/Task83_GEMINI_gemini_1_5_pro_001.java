import javax.crypto.*;
import javax.crypto.spec.IvParameterSpec;
import javax.crypto.spec.PBEKeySpec;
import javax.crypto.spec.SecretKeySpec;
import java.security.InvalidAlgorithmParameterException;
import java.security.InvalidKeyException;
import java.security.NoSuchAlgorithmException;
import java.security.SecureRandom;
import java.security.spec.InvalidKeySpecException;
import java.util.Base64;

public class Task83_GEMINI_gemini_1_5_pro_001 {

    public static void main(String[] args) throws NoSuchAlgorithmException,
            InvalidKeySpecException,
            InvalidAlgorithmParameterException,
            NoSuchPaddingException,
            IllegalBlockSizeException,
            BadPaddingException,
            InvalidKeyException {

        // Input key
        char[] key = "This is a secret key".toCharArray();
        // Input data to encrypt
        String data = "This is a secret message";
        // Generate a random salt
        byte[] salt = new byte[16];
        SecureRandom random = new SecureRandom();
        random.nextBytes(salt);

        // Derive a 256-bit key from the input key and salt
        SecretKeyFactory factory = SecretKeyFactory.getInstance("PBKDF2WithHmacSHA256");
        PBEKeySpec spec = new PBEKeySpec(key, salt, 390000, 256);
        SecretKey tmp = factory.generateSecret(spec);
        SecretKeySpec secretKey = new SecretKeySpec(tmp.getEncoded(), "AES");

        // Generate a random initialization vector (IV)
        byte[] iv = new byte[16];
        random.nextBytes(iv);
        IvParameterSpec ivspec = new IvParameterSpec(iv);

        // Create the AES-CBC cipher object
        Cipher cipher = Cipher.getInstance("AES/CBC/PKCS5Padding");
        cipher.init(Cipher.ENCRYPT_MODE, secretKey, ivspec);

        // Encrypt the data
        byte[] ciphertext = cipher.doFinal(data.getBytes());

        // Print the encrypted data in base64 encoding
        System.out.println(Base64.getEncoder().encodeToString(ciphertext));
    }
}