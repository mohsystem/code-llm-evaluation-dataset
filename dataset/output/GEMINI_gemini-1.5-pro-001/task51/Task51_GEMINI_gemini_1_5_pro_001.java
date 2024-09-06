public class Task51_GEMINI_gemini_1_5_pro_001 {
    public static String encrypt(String text, int key) {
        StringBuilder result = new StringBuilder();
        for (int i = 0; i < text.length(); i++) {
            char ch = text.charAt(i);
            if (Character.isLetter(ch)) {
                char start = Character.isLowerCase(ch) ? 'a' : 'A';
                char shiftedChar = (char) ((ch - start + key) % 26 + start);
                result.append(shiftedChar);
            } else if (Character.isDigit(ch)) {
                char shiftedChar = (char) (((ch - '0' + key) % 10) + '0');
                result.append(shiftedChar);
            } else {
                result.append(ch);
            }
        }
        return result.toString();
    }

    public static void main(String[] args) {
        String inputString = "Hello, world 123!";
        int encryptionKey = 3;
        String encryptedString = encrypt(inputString, encryptionKey);
        System.out.println("Encrypted: " + encryptedString);
    }
}