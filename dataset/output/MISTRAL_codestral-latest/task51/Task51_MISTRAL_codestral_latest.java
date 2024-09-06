public class Task51_MISTRAL_codestral_latest {
    public static void main(String[] args) {
        String inputString = "HELLO WORLD";
        int key = 3;
        String encryptedString = encryptString(inputString, key);
        System.out.println(encryptedString);
    }

    public static String encryptString(String inputString, int key) {
        StringBuilder encryptedString = new StringBuilder();
        for (char c : inputString.toCharArray()) {
            if (Character.isLetter(c)) {
                int asciiOffset = Character.isUpperCase(c) ? 65 : 97;
                encryptedString.append((char) ((c - asciiOffset + key) % 26 + asciiOffset));
            } else {
                encryptedString.append(c);
            }
        }
        return encryptedString.toString();
    }
}