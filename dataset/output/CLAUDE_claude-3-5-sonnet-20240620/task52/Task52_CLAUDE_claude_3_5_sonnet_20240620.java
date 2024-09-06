
import javax.crypto.Cipher;
import javax.crypto.KeyGenerator;
import javax.crypto.SecretKey;
import javax.crypto.spec.SecretKeySpec;
import java.io.*;
import java.security.NoSuchAlgorithmException;
import java.util.Base64;
import java.util.Scanner;

public class Task52_CLAUDE_claude_3_5_sonnet_20240620 {
    private static final String ALGORITHM = "AES";
    private static final String TRANSFORMATION = "AES";

    public static void encrypt(String key, File inputFile, File outputFile) throws Exception {
        doCrypto(Cipher.ENCRYPT_MODE, key, inputFile, outputFile);
    }

    public static void decrypt(String key, File inputFile, File outputFile) throws Exception {
        doCrypto(Cipher.DECRYPT_MODE, key, inputFile, outputFile);
    }

    private static void doCrypto(int cipherMode, String key, File inputFile, File outputFile) throws Exception {
        SecretKeySpec secretKey = new SecretKeySpec(key.getBytes(), ALGORITHM);
        Cipher cipher = Cipher.getInstance(TRANSFORMATION);
        cipher.init(cipherMode, secretKey);

        FileInputStream inputStream = new FileInputStream(inputFile);
        byte[] inputBytes = new byte[(int) inputFile.length()];
        inputStream.read(inputBytes);

        byte[] outputBytes = cipher.doFinal(inputBytes);

        FileOutputStream outputStream = new FileOutputStream(outputFile);
        outputStream.write(outputBytes);

        inputStream.close();
        outputStream.close();
    }

    public static String generateKey() throws NoSuchAlgorithmException {
        KeyGenerator keyGen = KeyGenerator.getInstance(ALGORITHM);
        keyGen.init(128);
        SecretKey secretKey = keyGen.generateKey();
        return Base64.getEncoder().encodeToString(secretKey.getEncoded());
    }

    public static void main(String[] args) {
        try {
            Scanner scanner = new Scanner(System.in);
            String key = generateKey();
            System.out.println("Generated key: " + key);

            System.out.print("Enter the file path to encrypt: ");
            String filePath = scanner.nextLine();

            File inputFile = new File(filePath);
            File encryptedFile = new File(filePath + ".encrypted");

            encrypt(key, inputFile, encryptedFile);
            System.out.println("File encrypted: " + encryptedFile.getPath());

            System.out.print("Do you want to decrypt the file? (y/n): ");
            String decryptChoice = scanner.nextLine();

            if (decryptChoice.equalsIgnoreCase("y")) {
                File decryptedFile = new File(filePath + ".decrypted");
                decrypt(key, encryptedFile, decryptedFile);
                System.out.println("File decrypted: " + decryptedFile.getPath());
            }

            scanner.close();
        } catch (Exception ex) {
            System.out.println("Error: " + ex.getMessage());
            ex.printStackTrace();
        }
    }
}
