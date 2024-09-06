// Java
import javax.crypto.KeyGenerator;
import javax.crypto.SecretKey;
import java.io.FileOutputStream;
import java.io.FileInputStream;
import java.io.IOException;
import java.security.NoSuchAlgorithmException;

public class Task134_MISTRAL_codestral_latest {
    public static SecretKey generateKey() throws NoSuchAlgorithmException {
        KeyGenerator keyGen = KeyGenerator.getInstance("AES");
        keyGen.init(256);
        return keyGen.generateKey();
    }

    public static void saveKey(SecretKey key, String filename) throws IOException {
        try (FileOutputStream fos = new FileOutputStream(filename)) {
            fos.write(key.getEncoded());
        }
    }

    public static SecretKey loadKey(String filename) throws IOException, NoSuchAlgorithmException {
        byte[] keyBytes = new byte[32];
        try (FileInputStream fis = new FileInputStream(filename)) {
            fis.read(keyBytes);
        }
        SecretKey key = new SecretKeySpec(keyBytes, "AES");
        return key;
    }
}