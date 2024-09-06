public class Task51_PERPLEXITY_llama_3_sonar_large_32k_chat {
    public static void main(String[] args) {
        String text = "Hello, World!";
        int shift = 3;
        System.out.println("Text : " + text);
        System.out.println("Shift : " + shift);
        System.out.println("Cipher: " + encrypt(text, shift));
    }

    public static String encrypt(String text, int shift) {
        StringBuilder result = new StringBuilder();

        for (char c : text.toCharArray()) {
            if (Character.isLetter(c)) {
                char base = Character.isUpperCase(c) ? 'A' : 'a';
                result.append((char) ((c - base + shift) % 26 + base));
            } else {
                result.append(c);
            }
        }

        return result.toString();
    }
}