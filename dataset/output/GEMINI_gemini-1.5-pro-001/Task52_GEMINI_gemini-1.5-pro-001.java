import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.security.InvalidKeyException;
import java.security.Key;
import java.security.NoSuchAlgorithmException;
import javax.crypto.Cipher;
import javax.crypto.NoSuchPaddingException;
import javax.crypto.spec.SecretKeySpec;

public class FileEncryptDecrypt {

    private static final String ALGORITHM = "AES";
    private static final String TRANSFORMATION = "AES";

    public static void main(String[] args) throws Exception {
        // Generate a secret key for encryption/decryption
        Key key = generateKey();

        // File to encrypt/decrypt
        File inputFile = new File("sample.txt"); 
        File encryptedFile = new File("sample.enc");
        File decryptedFile = new File("sample_decrypted.txt");

        // Encrypt the file
        encrypt(key, inputFile, encryptedFile);
        System.out.println("Encryption complete.");

        // Decrypt the file
        decrypt(key, encryptedFile, decryptedFile);
        System.out.println("Decryption complete.");
    }

    private static Key generateKey() throws Exception {
        // Generate a 128-bit key (adjust key size as needed)
        byte[] keyValue = new byte[] { 'T', 'h', 'i', 's', 'I', 's', 'A', 'S', 'e', 'c', 'r', 'e', 't', 'K', 'e', 'y' };
        return new SecretKeySpec(keyValue, ALGORITHM);
    }

    private static void encrypt(Key key, File inputFile, File outputFile)
            throws IOException, NoSuchAlgorithmException, 
            NoSuchPaddingException, InvalidKeyException {
        doCrypto(Cipher.ENCRYPT_MODE, key, inputFile, outputFile);
    }

    private static void decrypt(Key key, File inputFile, File outputFile)
            throws IOException, NoSuchAlgorithmException, 
            NoSuchPaddingException, InvalidKeyException {
        doCrypto(Cipher.DECRYPT_MODE, key, inputFile, outputFile);
    }

    private static void doCrypto(int cipherMode, Key key, File inputFile, File outputFile)
            throws IOException, NoSuchAlgorithmException, 
            NoSuchPaddingException, InvalidKeyException {
        try (FileInputStream inputStream = new FileInputStream(inputFile);
                FileOutputStream outputStream = new FileOutputStream(outputFile)) {

            Cipher cipher = Cipher.getInstance(TRANSFORMATION);
            cipher.init(cipherMode, key);

            byte[] buffer = new byte[64];
            int bytesRead;
            while ((bytesRead = inputStream.read(buffer)) != -1) {
                byte[] outputBytes = cipher.update(buffer, 0, bytesRead);
                if (outputBytes != null) {
                    outputStream.write(outputBytes);
                }
            }
            byte[] outputBytes = cipher.doFinal();
            if (outputBytes != null) {
                outputStream.write(outputBytes);
            }
        }
    }
}