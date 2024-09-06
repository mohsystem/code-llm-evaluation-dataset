
import java.util.Scanner;

public class Task51_CLAUDE_claude_3_5_sonnet_20240620 {
    public static String encrypt(String text, int shift) {
        StringBuilder result = new StringBuilder();
        for (char character : text.toCharArray()) {
            if (Character.isLetter(character)) {
                int asciiOffset = Character.isUpperCase(character) ? 65 : 97;
                char shiftedChar = (char) ((character - asciiOffset + shift) % 26 + asciiOffset);
                result.append(shiftedChar);
            } else {
                result.append(character);
            }
        }
        return result.toString();
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter text to encrypt: ");
        String text = scanner.nextLine();
        System.out.print("Enter shift value: ");
        int shift = scanner.nextInt();
        String encryptedText = encrypt(text, shift);
        System.out.println("Encrypted text: " + encryptedText);
        scanner.close();
    }
}
