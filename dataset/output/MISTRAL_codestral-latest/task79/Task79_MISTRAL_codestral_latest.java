// Java
public class Task79_MISTRAL_codestral_latest {
    public static String encrypt(String message, int key) {
        StringBuilder cipher = new StringBuilder();
        for (char character : message.toCharArray()) {
            if (Character.isLetter(character)) {
                char shifted = Character.isUpperCase(character) ? 'A' : 'a';
                cipher.append((char) ((character - shifted + key) % 26 + shifted));
            } else {
                cipher.append(character);
            }
        }
        return cipher.toString();
    }

    public static void main(String[] args) {
        String message = "HELLO WORLD";
        int key = 3;
        String encryptedMessage = encrypt(message, key);
        System.out.println(encryptedMessage);
    }
}