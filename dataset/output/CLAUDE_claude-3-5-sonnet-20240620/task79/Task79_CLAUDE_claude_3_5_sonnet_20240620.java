
import java.util.ArrayList;
import java.util.Collections;
import java.util.Random;

public class Task79_CLAUDE_claude_3_5_sonnet_20240620 {
    public static String encryptMessage(String message, int key) {
        ArrayList<Character> cipher = new ArrayList<>();
        for (char c = 'A'; c <= 'Z'; c++) {
            cipher.add(c);
        }
        
        Random random = new Random(key);
        Collections.shuffle(cipher, random);
        
        StringBuilder encrypted = new StringBuilder();
        for (char c : message.toUpperCase().toCharArray()) {
            if (Character.isLetter(c)) {
                int index = c - 'A';
                encrypted.append(cipher.get(index));
            } else {
                encrypted.append(c);
            }
        }
        
        return encrypted.toString();
    }

    public static void main(String[] args) {
        String message = "Hello, World!";
        int key = 42;
        String encrypted = encryptMessage(message, key);
        System.out.println("Original: " + message);
        System.out.println("Encrypted: " + encrypted);
    }
}
