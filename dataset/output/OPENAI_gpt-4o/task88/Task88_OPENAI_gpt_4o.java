import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.StandardOpenOption;
import java.nio.charset.StandardCharsets;
import java.util.Random;

public class Task88_OPENAI_gpt_4o {
    public static void main(String[] args) throws Exception {
        // Generate a random string
        String characters = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
        StringBuilder randomString = new StringBuilder();
        Random rnd = new Random();
        while (randomString.length() < 10) {
            int index = (int) (rnd.nextFloat() * characters.length());
            randomString.append(characters.charAt(index));
        }

        // Convert string into Unicode
        byte[] unicodeString = randomString.toString().getBytes(StandardCharsets.UTF_8);

        // Create a temporary file and write the Unicode string to it
        Path tempFile = Files.createTempFile(null, null);
        Files.write(tempFile, unicodeString, StandardOpenOption.WRITE);

        // Output the path of the temporary file
        System.out.println(tempFile.toString());
    }
}