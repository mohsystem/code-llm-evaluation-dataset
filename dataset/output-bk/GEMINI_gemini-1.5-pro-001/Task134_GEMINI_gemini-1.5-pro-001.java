import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.security.InvalidKeyException;
import java.security.NoSuchAlgorithmException;
import java.util.Base64;
import java.util.Scanner;

import javax.crypto.Cipher;
import javax.crypto.KeyGenerator;
import javax.crypto.NoSuchPaddingException;
import javax.crypto.SecretKey;

public class CryptoKeyManager {

    private static final String ALGORITHM = "AES";
    private static final String KEY_FILE = "secret.key";

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        while (true) {
            System.out.println("
Choose an option:");
            System.out.println("1. Generate a new key");
            System.out.println("2. Load an existing key");
            System.out.println("3. Encrypt a message");
            System.out.println("4. Decrypt a message");
            System.out.println("5. Exit");

            System.out.print("
Enter your choice: ");
            int choice = scanner.nextInt();
            scanner.nextLine(); // Consume newline

            try {
                switch (choice) {
                    case 1:
                        generateKey();
                        System.out.println("Key generated and saved to 'secret.key'");
                        break;
                    case 2:
                        loadKey();
                        System.out.println("Key loaded successfully!");
                        break;
                    case 3:
                        System.out.print("Enter the message to encrypt: ");
                        String messageToEncrypt = scanner.nextLine();
                        SecretKey encryptionKey = loadKey();
                        String encryptedMessage = encryptMessage(messageToEncrypt, encryptionKey);
                        System.out.println("Encrypted message: " + encryptedMessage);
                        break;
                    case 4:
                        System.out.print("Enter the message to decrypt: ");
                        String messageToDecrypt = scanner.nextLine();
                        SecretKey decryptionKey = loadKey();
                        String decryptedMessage = decryptMessage(messageToDecrypt, decryptionKey);
                        System.out.println("Decrypted message: " + decryptedMessage);
                        break;
                    case 5:
                        System.out.println("Exiting...");
                        scanner.close();
                        return;
                    default:
                        System.out.println("Invalid choice!");
                }
            } catch (Exception e) {
                System.out.println("An error occurred: " + e.getMessage());
            }
        }
    }

    private static void generateKey() throws NoSuchAlgorithmException, IOException {
        KeyGenerator keyGenerator = KeyGenerator.getInstance(ALGORITHM);
        keyGenerator.init(128); // Use a keysize of 128 bits
        SecretKey key = keyGenerator.generateKey();

        // Store the key in a file
        File keyFile = new File(KEY_FILE);
        FileOutputStream outputStream = new FileOutputStream(keyFile);
        outputStream.write(key.getEncoded());
        outputStream.close();
    }

    private static SecretKey loadKey() throws IOException {
        File keyFile = new File(KEY_FILE);
        FileInputStream inputStream = new FileInputStream(keyFile);
        byte[] encodedKey = new byte[(int) keyFile.length()];
        inputStream.read(encodedKey);
        inputStream.close();

        return new javax.crypto.spec.SecretKeySpec(encodedKey, ALGORITHM);
    }

    private static String encryptMessage(String message, SecretKey key)
            throws NoSuchAlgorithmException, NoSuchPaddingException, InvalidKeyException,
            javax.crypto.IllegalBlockSizeException, javax.crypto.BadPaddingException {
        Cipher cipher = Cipher.getInstance(ALGORITHM);
        cipher.init(Cipher.ENCRYPT_MODE, key);

        byte[] encryptedBytes = cipher.doFinal(message.getBytes());
        return Base64.getEncoder().encodeToString(encryptedBytes);
    }

    private static String decryptMessage(String encryptedMessage, SecretKey key)
            throws NoSuchAlgorithmException, NoSuchPaddingException, InvalidKeyException,
            javax.crypto.IllegalBlockSizeException, javax.crypto.BadPaddingException {
        Cipher cipher = Cipher.getInstance(ALGORITHM);
        cipher.init(Cipher.DECRYPT_MODE, key);

        byte[] decryptedBytes = cipher.doFinal(Base64.getDecoder().decode(encryptedMessage));
        return new String(decryptedBytes);
    }
}