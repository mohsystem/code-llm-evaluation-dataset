// Java
// This is a simple example using AES encryption algorithm.
// Please note that you need to add Bouncy Castle Provider to your project.
import javax.crypto.Cipher;
import javax.crypto.CipherInputStream;
import javax.crypto.CipherOutputStream;
import javax.crypto.spec.IvParameterSpec;
import javax.crypto.spec.SecretKeySpec;
import java.io.*;
import java.security.SecureRandom;

public class Task52_MISTRAL_codestral_latest {
    private static final String ALGORITHM = "AES";
    private static final String TRANSFORMATION = "AES/CBC/PKCS5Padding";

    public static void encryptFile(String key, File inputFile, File outputFile) throws Exception {
        SecretKeySpec secretKey = new SecretKeySpec(key.getBytes(), ALGORITHM);
        Cipher cipher = Cipher.getInstance(TRANSFORMATION);
        SecureRandom randomSecureRandom = new SecureRandom();
        byte[] iv = new byte[cipher.getBlockSize()];
        randomSecureRandom.nextBytes(iv);
        IvParameterSpec ivParams = new IvParameterSpec(iv);
        cipher.init(Cipher.ENCRYPT_MODE, secretKey, ivParams);

        try (FileOutputStream fileOutputStream = new FileOutputStream(outputFile);
             CipherOutputStream cipherOutputStream = new CipherOutputStream(fileOutputStream, cipher)) {
            fileOutputStream.write(iv);
            copy(new FileInputStream(inputFile), cipherOutputStream);
        }
    }

    public static void decryptFile(String key, File inputFile, File outputFile) throws Exception {
        SecretKeySpec secretKey = new SecretKeySpec(key.getBytes(), ALGORITHM);
        Cipher cipher = Cipher.getInstance(TRANSFORMATION);

        try (FileInputStream fileInputStream = new FileInputStream(inputFile)) {
            byte[] iv = new byte[cipher.getBlockSize()];
            fileInputStream.read(iv);
            IvParameterSpec ivParams = new IvParameterSpec(iv);
            cipher.init(Cipher.DECRYPT_MODE, secretKey, ivParams);

            try (CipherInputStream cipherInputStream = new CipherInputStream(fileInputStream, cipher);
                 FileOutputStream fileOutputStream = new FileOutputStream(outputFile)) {
                copy(cipherInputStream, fileOutputStream);
            }
        }
    }

    private static void copy(InputStream input, OutputStream output) throws IOException {
        byte[] buffer = new byte[1024];
        int length;
        while ((length = input.read(buffer)) != -1) {
            output.write(buffer, 0, length);
        }
    }
}