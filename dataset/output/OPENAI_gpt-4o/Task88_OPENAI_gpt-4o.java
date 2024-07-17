import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Path;
import java.util.Random;

public class Main {
    public static void main(String[] args) throws IOException {
        // Random string generation
        byte[] array = new byte[7]; // length of the random string
        new Random().nextBytes(array);
        String randomString = new String(array, StandardCharsets.UTF_8);

        // Convert string to Unicode
        String unicodeString = new String(randomString.getBytes(StandardCharsets.UTF_8), StandardCharsets.UTF_8);

        // Create temporary file
        File tempFile = File.createTempFile("tempFile", ".txt");

        // Write to the file
        FileWriter writer = new FileWriter(tempFile, StandardCharsets.UTF_8);
        writer.write(unicodeString);
        writer.close();

        // Return the path
        System.out.println("File path: " + tempFile.getAbsolutePath());
    }
}