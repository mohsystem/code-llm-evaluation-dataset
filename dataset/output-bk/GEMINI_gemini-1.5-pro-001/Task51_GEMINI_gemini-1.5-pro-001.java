import java.util.Scanner;

public class Encrypt {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter a string to encrypt: ");
        String message = scanner.nextLine();

        String encryptedMessage = encrypt(message);
        System.out.println("Encrypted message: " + encryptedMessage);
    }

    public static String encrypt(String message) {
        StringBuilder encrypted = new StringBuilder();
        for (char c : message.toCharArray()) {
            encrypted.append((char) (c + 3)); // Simple Caesar cipher with a shift of 3
        }
        return encrypted.toString();
    }
}