import java.nio.file.*;
import javax.crypto.*;
import javax.crypto.spec.SecretKeySpec;
import java.util.Base64;
import java.io.IOException;
import java.nio.file.Files;

public class Task52_OPENAI_gpt_4o {

    private static final String ALGORITHM = "AES";

    private static SecretKey generateKey() throws Exception {
        KeyGenerator keyGen = KeyGenerator.getInstance(ALGORITHM);
        keyGen.init(128);
        return keyGen.generateKey();
    }

    private static void saveKey(SecretKey key, Path path) throws IOException {
        byte[] encoded = Base64.getEncoder().encode(key.getEncoded());
        Files.write(path, encoded);
    }

    private static SecretKey loadKey(Path path) throws IOException {
        byte[] encoded = Files.readAllBytes(path);
        byte[] keyBytes = Base64.getDecoder().decode(encoded);
        return new SecretKeySpec(keyBytes, ALGORITHM);
    }

    private static void encryptFile(SecretKey key, Path inputFile, Path outputFile) throws Exception {
        Cipher cipher = Cipher.getInstance(ALGORITHM);
        cipher.init(Cipher.ENCRYPT_MODE, key);

        byte[] inputBytes = Files.readAllBytes(inputFile);
        byte[] outputBytes = cipher.doFinal(inputBytes);

        Files.write(outputFile, outputBytes);
    }

    private static void decryptFile(SecretKey key, Path inputFile, Path outputFile) throws Exception {
        Cipher cipher = Cipher.getInstance(ALGORITHM);
        cipher.init(Cipher.DECRYPT_MODE, key);

        byte[] inputBytes = Files.readAllBytes(inputFile);
        byte[] outputBytes = cipher.doFinal(inputBytes);

        Files.write(outputFile, outputBytes);
    }

    public static void main(String[] args) throws Exception {
        Path keyPath = Paths.get("filekey.key");
        Path inputFile = Paths.get("test.txt");
        Path encryptedFile = inputFile.resolveSibling("test.encrypted");
        Path decryptedFile = inputFile.resolveSibling("test.decrypted");

        SecretKey key = generateKey();
        saveKey(key, keyPath);

        encryptFile(key, inputFile, encryptedFile);
        decryptFile(key, encryptedFile, decryptedFile);
    }
}