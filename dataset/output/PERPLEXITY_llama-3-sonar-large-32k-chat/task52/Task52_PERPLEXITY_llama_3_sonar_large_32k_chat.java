// Java code
import java.io.*;

public class Task52_PERPLEXITY_llama_3_sonar_large_32k_chat {
    public static String caesarEncrypt(String text, int shift) {
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

    public static String caesarDecrypt(String text, int shift) {
        StringBuilder result = new StringBuilder();

        for (char c : text.toCharArray()) {
            if (Character.isLetter(c)) {
                char base = Character.isUpperCase(c) ? 'A' : 'a';
                result.append((char) ((c - base - shift) % 26 + base));
            } else {
                result.append(c);
            }
        }

        return result.toString();
    }

    public static void encryptFile(String filePath, int shift) throws IOException {
        File file = new File(filePath);
        String text = new String(Files.readAllBytes(file.toPath));
        String encryptedText = caesarEncrypt(text, shift);
        FileWriter writer = new FileWriter(file);
        writer.write(encryptedText);
        writer.close();
    }

    public static void decryptFile(String filePath, int shift) throws IOException {
        File file = new File(filePath);
        String text = new String(Files.readAllBytes(file.toPath()));
        String decryptedText = caesarDecrypt(text, shift);
        FileWriter writer = new FileWriter(file);
        writer.write(decryptedText);
        writer.close();
    }

    public static void main(String[] args) throws IOException {
        String filePath = "example.txt";
        int shift = 3;
        encryptFile(filePath, shift);
        decryptFile(filePath, shift);
    }
}