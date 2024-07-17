import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.nio.charset.StandardCharsets;
import java.util.Random;

public class TempFileUnicode {
    public static void main(String[] args) throws IOException {
        File tempFile = File.createTempFile("temp", ".txt");
        String randomString = generateRandomString(10);
        String unicodeString = convertToUnicode(randomString);

        try (FileOutputStream outputStream = new FileOutputStream(tempFile)) {
            outputStream.write(unicodeString.getBytes(StandardCharsets.UTF_8));
        }

        System.out.println(tempFile.getAbsolutePath());
    }

    private static String generateRandomString(int length) {
        Random random = new Random();
        StringBuilder sb = new StringBuilder(length);
        String characters = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
        for (int i = 0; i < length; i++) {
            sb.append(characters.charAt(random.nextInt(characters.length())));
        }
        return sb.toString();
    }

    private static String convertToUnicode(String str) {
        StringBuilder sb = new StringBuilder();
        for (char c : str.toCharArray()) {
            sb.append("\\u").append(String.format("%04X", (int) c));
        }
        return sb.toString();
    }
}