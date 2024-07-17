import javax.crypto.Cipher;
import java.security.*;
import java.util.Base64;

public class RSAEncryption {

    public static void main(String[] args) throws Exception {
        // Generate key pair
        KeyPairGenerator generator = KeyPairGenerator.getInstance("RSA");
        generator.initialize(2048);
        KeyPair keyPair = generator.generateKeyPair();
        PrivateKey privateKey = keyPair.getPrivate();
        PublicKey publicKey = keyPair.getPublic();

        // Encrypt message
        String message = "Hello, RSA!";
        Cipher encryptCipher = Cipher.getInstance("RSA/ECB/PKCS1Padding");
        encryptCipher.init(Cipher.ENCRYPT_MODE, publicKey);
        byte[] encryptedMessage = encryptCipher.doFinal(message.getBytes());
        String encodedEncryptedMessage = Base64.getEncoder().encodeToString(encryptedMessage);

        // Decrypt message
        Cipher decryptCipher = Cipher.getInstance("RSA/ECB/PKCS1Padding");
        decryptCipher.init(Cipher.DECRYPT_MODE, privateKey);
        byte[] decryptedMessage = decryptCipher.doFinal(Base64.getDecoder().decode(encodedEncryptedMessage));
        String decryptedMessageString = new String(decryptedMessage);

        System.out.println("Ciphertext: " + encodedEncryptedMessage);
        System.out.println("Plaintext: " + decryptedMessageString);
    }
}