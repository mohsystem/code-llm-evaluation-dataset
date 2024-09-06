import javax.crypto.Cipher;
import java.security.*;
import java.util.Base64;

public class Task106_GEMINI_gemini_1_5_pro_001 {

    public static void main(String[] args) throws Exception {
        // Generate public and private keys
        KeyPairGenerator generator = KeyPairGenerator.getInstance("RSA");
        generator.initialize(2048);
        KeyPair pair = generator.generateKeyPair();
        PublicKey publicKey = pair.getPublic();
        PrivateKey privateKey = pair.getPrivate();

        // Encrypt the message
        String message = "This is a secret message";
        Cipher encryptionCipher = Cipher.getInstance("RSA/ECB/OAEPWithSHA-256AndMGF1Padding");
        encryptionCipher.init(Cipher.ENCRYPT_MODE, publicKey);
        byte[] encryptedMessage = encryptionCipher.doFinal(message.getBytes());
        String encodedEncryptedMessage = Base64.getEncoder().encodeToString(encryptedMessage);

        // Decrypt the message
        Cipher decryptionCipher = Cipher.getInstance("RSA/ECB/OAEPWithSHA-256AndMGF1Padding");
        decryptionCipher.init(Cipher.DECRYPT_MODE, privateKey);
        byte[] decryptedMessage = decryptionCipher.doFinal(Base64.getDecoder().decode(encodedEncryptedMessage));
        String decryptedMessageString = new String(decryptedMessage);

        // Print the results
        System.out.println("Original Message: " + message);
        System.out.println("Encrypted Message: " + encodedEncryptedMessage);
        System.out.println("Decrypted Message: " + decryptedMessageString);
    }
}