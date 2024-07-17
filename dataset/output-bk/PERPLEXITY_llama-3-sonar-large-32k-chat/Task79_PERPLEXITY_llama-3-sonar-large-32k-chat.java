public class Main {
    public static void main(String[] args) {
        String message = "Hello, World!";
        String secretKey = "mySecretKey";
        String cipher = createCipher(secretKey);
        String encryptedMessage = encryptMessage(message, cipher);
        System.out.println("Encrypted Message: " + encryptedMessage);
    }

    public static String createCipher(String secretKey) {
        return secretKey.repeat(10); // simple repetition cipher
    }

    public static String encryptMessage(String message, String cipher) {
        StringBuilder encryptedMessage = new StringBuilder();
        for (int i = 0; i < message.length(); i++) {
            encryptedMessage.append((char) (message.charAt(i) + cipher.charAt(i % cipher.length())));
        }
        return encryptedMessage.toString();
    }
}