import javax.crypto.Cipher;
import javax.crypto.KeyGenerator;
import javax.crypto.SecretKey;
import javax.crypto.spec.IvParameterSpec;
import java.security.SecureRandom;
import java.util.Base64;

public class AESEncryption {

    public static void main(String[] args) throws Exception {
        // Generate a secret key
        SecretKey secretKey = KeyGenerator.getInstance("AES").generateKey();

        // Generate a random 16-byte initialization vector
        byte[] iv = new byte[16];
        SecureRandom random = new SecureRandom();
        random.nextBytes(iv);
        IvParameterSpec ivParameterSpec = new IvParameterSpec(iv);

        // Create the cipher in encryption mode
        Cipher cipher = Cipher.getInstance("AES/CBC/PKCS5Padding");
        cipher.init(Cipher.ENCRYPT_MODE, secretKey, ivParameterSpec);

        // Encrypt the key
        byte[] encryptedKey = cipher.doFinal(secretKey.getEncoded());

        // Encode the encrypted key and IV in Base64
        String encodedEncryptedKey = Base64.getEncoder().encodeToString(encryptedKey);
        String encodedIV = Base64.getEncoder().encodeToString(iv);

        // Print the results
        System.out.println("Encrypted Key (Base64): " + encodedEncryptedKey);
        System.out.println("IV (Base64): " + encodedIV);
    }
}