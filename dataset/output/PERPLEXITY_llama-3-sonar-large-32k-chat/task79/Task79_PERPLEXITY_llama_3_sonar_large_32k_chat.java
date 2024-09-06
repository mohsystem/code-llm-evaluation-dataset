code here:
import java.util.HashMap;
import java.util.Map;

public class Task79_PERPLEXITY_llama_3_sonar_large_32k_chat {
    public static Map<Character, Character> createCipher(int key) {
        Map<Character, Character> cipher = new HashMap<>();
        for (int i = 0; i < 26; i++) {
            cipher.put((char) (65 + i), (char) (65 + (i + key) % 26));
            cipher.put((char) (97 + i), (char) (97 + (i + key) % 26));
        }
        return cipher;
    }

    public static String encryptMessage(String message, int key) {
        Map<Character, Character> cipher = createCipher(key);
        StringBuilder encryptedMessage = new StringBuilder();
        for (char c : message.toCharArray()) {
            if (cipher.containsKey(c)) {
                encryptedMessage.append(cipher.get(c));
            } else {
                encryptedMessage.append(c);
            }
        }
        return encryptedMessage.toString();
    }

    public static void main(String[] args) {
        int key = 3;
        String message = "Hello, World!";
        System.out.println("Original Message: " + message);
        System.out.println("Encrypted Message: " + encryptMessage(message, key));
    }
}