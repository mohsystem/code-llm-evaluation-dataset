import javax.crypto.Cipher;
import javax.crypto.KeyGenerator;
import javax.crypto.SecretKey;
import javax.crypto.spec.SecretKeySpec;
import java.io.*;
import java.security.SecureRandom;

public class FileEncryption {
    public static void main(String[] args) throws Exception {
        String algorithm = "AES";
        String fileToEncrypt = "input.txt";
        String encryptedFile = "encrypted.txt";
        String decryptedFile = "decrypted.txt";

        KeyGenerator kgen = KeyGenerator.getInstance(algorithm);
        SecureRandom random = new SecureRandom();
        kgen.init(128, random);
        SecretKey skey = kgen.generateKey();
        byte[] raw = skey.getEncoded();

        SecretKeySpec skeySpec = new SecretKeySpec(raw, algorithm);

        Cipher cipher = Cipher.getInstance(algorithm);
        cipher.init(Cipher.ENCRYPT_MODE, skeySpec);

        encrypt(fileToEncrypt, encryptedFile, cipher);

        cipher.init(Cipher.DECRYPT_MODE, skeySpec);
        decrypt(encryptedFile, decryptedFile, cipher);
    }

    public static void encrypt(String fileToEncrypt, String encryptedFile, Cipher cipher) throws Exception {
        FileInputStream fis = new FileInputStream(fileToEncrypt);
        FileOutputStream fos = new FileOutputStream(encryptedFile);
        byte[] buffer = new byte[64];
        int bytesRead;
        while ((bytesRead = fis.read(buffer)) != -1) {
            byte[] output = cipher.update(buffer, 0, bytesRead);
            if (output != null) {
                fos.write(output);
            }
        }
        byte[] output = cipher.doFinal();
        if (output != null) {
            fos.write(output);
        }
        fis.close();
        fos.close();
    }

    public static void decrypt(String encryptedFile, String decryptedFile, Cipher cipher) throws Exception {
        FileInputStream fis = new FileInputStream(encryptedFile);
        FileOutputStream fos = new FileOutputStream(decryptedFile);
        byte[] buffer = new byte[64];
        int bytesRead;
        while ((bytesRead = fis.read(buffer)) != -1) {
            byte[] output = cipher.update(buffer, 0, bytesRead);
            if (output != null) {
                fos.write(output);
            }
        }
        byte[] output = cipher.doFinal();
        if (output != null) {
            fos.write(output);
        }
        fis.close();
        fos.close();
    }
}