
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.nio.charset.StandardCharsets;
import java.util.Random;

public class Task88_CLAUDE_claude_3_5_sonnet_20240620 {
    public static String createTempFileWithUnicode() throws IOException {
        // Create a temporary file
        File tempFile = File.createTempFile("temp", ".txt");
        
        // Generate a random string
        String randomString = generateRandomString(10);
        
        // Convert the string to Unicode
        String unicodeString = convertToUnicode(randomString);
        
        // Write the Unicode string to the file
        try (FileWriter writer = new FileWriter(tempFile, StandardCharsets.UTF_8)) {
            writer.write(unicodeString);
        }
        
        return tempFile.getAbsolutePath();
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
    
    public static void main(String[] args) {
        try {
            System.out.println(createTempFileWithUnicode());
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
