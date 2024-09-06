// Java code for RSA encryption and decryption is quite lengthy and requires external libraries.
// This example uses Bouncy Castle library for RSA implementation.
// Please make sure to include the Bouncy Castle library in your project.

import java.security.KeyPair;
import java.security.KeyPairGenerator;
import java.security.PrivateKey;
import java.security.PublicKey;
import java.util.Base64;
import javax.crypto.Cipher;
import org.bouncycastle.jce.provider.BouncyCastleProvider;

public class Task106_MISTRAL_codestral_latest {
    public static void main(String[] args) throws Exception {
        // Generate a new RSA key pair
        KeyPairGenerator keyPairGenerator = KeyPairGenerator.getInstance("RSA", new BouncyCastleProvider());
        keyPairGenerator.initialize(2048);
        KeyPair keyPair = keyPairGenerator.generateKeyPair();
        PublicKey publicKey = keyPair.getPublic();
        PrivateKey privateKey = keyPair.getPrivate();

        // Data to be encrypted
        String data = "Hello, World!";

        // Encrypt the data
        Cipher cipher = Cipher.getInstance("RSA/None/PKCS1Padding", new BouncyCastleProvider());
        cipher.init(Cipher.ENCRYPT_MODE, publicKey);
        byte[] encryptedData = cipher.doFinal(data.getBytes());

        // Decrypt the data
        cipher.init(Cipher.DECRYPT_MODE, privateKey);
        byte[] decryptedData = cipher.doFinal(encryptedData);

        System.out.println("Encrypted data: " + Base64.getEncoder().encodeToString(encryptedData));
        System.out.println("Decrypted data: " + new String(decryptedData));
    }
}