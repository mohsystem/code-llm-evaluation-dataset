import java.security.InvalidKeyException;
import java.security.NoSuchAlgorithmException;
import java.util.Base64;
import java.util.Scanner;
import javax.crypto.Cipher;
import javax.crypto.KeyGenerator;
import javax.crypto.NoSuchPaddingException;
import javax.crypto.SecretKey;

public class Task134_GEMINI_gemini_1_5_pro_001 {

    private static SecretKey key;
    private static final String ALGORITHM = "AES";

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        while (true) {
            System.out.println("\nCryptographic Key Manager:");
            System.out.println("1. Generate a new key");
            System.out.println("2. Encrypt a message");
            System.out.println("3. Decrypt a message");
            System.out.println("4. Exit");

            System.out.print("Enter your choice: ");
            int choice = scanner.nextInt();
            scanner.nextLine(); 

            try {
                switch (choice) {
                    case 1:
                        generateKey();
                        System.out.println("New key generated.");
                        break;
                    case 2:
                        System.out.print("Enter the message to encrypt: ");
                        String messageToEncrypt = scanner.nextLine();
                        String encryptedMessage = encrypt(messageToEncrypt, key);
                        System.out.println("Encrypted message: " + encryptedMessage);
                        break;
                    case 3:
                        System.out.print("Enter the message to decrypt: ");
                        String messageToDecrypt = scanner.nextLine();
                        String decryptedMessage = decrypt(messageToDecrypt, key);
                        System.out.println("Decrypted message: " + decryptedMessage);
                        break;
                    case 4:
                        System.out.println("Exiting...");
                        scanner.close();
                        System.exit(0);
                    default:
                        System.out.println("Invalid choice. Please try again.");
                }
            } catch (Exception e) {
                System.err.println("An error occurred: " + e.getMessage());
            }
        }
    }

    public static void generateKey() throws NoSuchAlgorithmException {
        KeyGenerator keyGenerator = KeyGenerator.getInstance(ALGORITHM);
        keyGenerator.init(128); 
        key = keyGenerator.generateKey();
    }

    public static String encrypt(String message, SecretKey secretKey) throws NoSuchAlgorithmException,
            NoSuchPaddingException, InvalidKeyException, IllegalBlockSizeException, BadPaddingException {
        Cipher cipher = Cipher.getInstance(ALGORITHM);
        cipher.init(Cipher.ENCRYPT_MODE, secretKey);
        return Base64.getEncoder().encodeToString(cipher.doFinal(message.getBytes()));
    }

    public static String decrypt(String encryptedMessage, SecretKey secretKey) throws NoSuchAlgorithmException,
            NoSuchPaddingException, InvalidKeyException, IllegalBlockSizeException, BadPaddingException {
        Cipher cipher = Cipher.getInstance(ALGORITHM);
        cipher.init(Cipher.DECRYPT_MODE, secretKey);
        return new String(cipher.doFinal(Base64.getDecoder().decode(encryptedMessage)));
    }
}