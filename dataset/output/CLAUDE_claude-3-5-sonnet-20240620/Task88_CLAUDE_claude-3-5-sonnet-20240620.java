
import java.io.*;
import java.nio.charset.StandardCharsets;
import java.nio.file.*;
import java.util.Random;

public class TempFileUnicode {
    public static void main(String[] args) {
        try {
            Path tempFile = Files.createTempFile("unicode_", ".txt");
            String randomString = generateRandomString(10);
            String unicodeString = convertToUnicode(randomString);
            
            try (BufferedWriter writer = Files.newBufferedWriter(tempFile, StandardCharsets.UTF_8)) {
                writer.write(unicodeString);
            }
            
            System.out.println("Temporary file path: " + tempFile.toAbsolutePath());
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    private static String generateRandomString(int length) {
        String chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
        StringBuilder sb = new StringBuilder();
        Random random = new Random();
        for (int i = 0; i < length; i++) {
            sb.append(chars.charAt(random.nextInt(chars.length())));
        }
        return sb.toString();
    }

    private static String convertToUnicode(String input) {
        StringBuilder sb = new StringBuilder();
        for (char c : input.toCharArray()) {
            sb.append(String.format("\\\\u%04x", (int) c));
        }
        return sb.toString();
    }
}
