import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.security.InvalidKeyException;
import java.security.NoSuchAlgorithmException;
import javax.crypto.Cipher;
import javax.crypto.KeyGenerator;
import javax.crypto.NoSuchPaddingException;
import javax.crypto.SecretKey;
import javax.crypto.spec.SecretKeySpec;

public class Task52_GEMINI_gemini_1_5_pro_001 {

    public static void main(String[] args) {
        try {
            // Generate a new key
            SecretKey secretKey = generateKey();
            // Get the key bytes
            byte[] keyBytes = secretKey.getEncoded();
            // Create a SecretKeySpec from the key bytes
            SecretKeySpec keySpec = new SecretKeySpec(keyBytes, "AES");

            String inputFile = "test.txt";
            String encryptedFile = "encrypted.txt";
            String decryptedFile = "decrypted.txt";

            // Encrypt the file
            encryptFile(keySpec, inputFile, encryptedFile);
            System.out.println("File encrypted successfully.");

            // Decrypt the file
            decryptFile(keySpec, encryptedFile, decryptedFile);
            System.out.println("File decrypted successfully.");

        } catch (Exception ex) {
            ex.printStackTrace();
        }
    }

    public static SecretKey generateKey() throws NoSuchAlgorithmException {
        KeyGenerator keyGen = KeyGenerator.getInstance("AES");
        keyGen.init(128); // for example
        return keyGen.generateKey();
    }

    public static void encryptFile(SecretKeySpec key, String inputFile, String outputFile)
            throws IOException, NoSuchAlgorithmException, NoSuchPaddingException, InvalidKeyException {
        Cipher cipher = Cipher.getInstance("AES");
        cipher.init(Cipher.ENCRYPT_MODE, key);

        try (FileInputStream fis = new FileInputStream(inputFile);
             FileOutputStream fos = new FileOutputStream(outputFile)) {

            byte[] in = new byte[64];
            int bytesRead;
            while ((bytesRead = fis.read(in)) != -1) {
                byte[] out = cipher.update(in, 0, bytesRead);
                if (out != null) {
                    fos.write(out);
                }
            }
            byte[] out = cipher.doFinal();
            if (out != null) {
                fos.write(out);
            }
        }
    }

    public static void decryptFile(SecretKeySpec key, String inputFile, String outputFile)
            throws IOException, NoSuchAlgorithmException, NoSuchPaddingException, InvalidKeyException {
        Cipher cipher = Cipher.getInstance("AES");
        cipher.init(Cipher.DECRYPT_MODE, key);

        try (FileInputStream fis = new FileInputStream(inputFile);
             FileOutputStream fos = new FileOutputStream(outputFile)) {

            byte[] in = new byte[64];
            int bytesRead;
            while ((bytesRead = fis.read(in)) != -1) {
                byte[] out = cipher.update(in, 0, bytesRead);
                if (out != null) {
                    fos.write(out);
                }
            }
            byte[] out = cipher.doFinal();
            if (out != null) {
                fos.write(out);
            }
        }
    }
}