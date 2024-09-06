import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.nio.charset.StandardCharsets;
import java.util.UUID;

public class Task88_GEMINI_gemini_1_5_pro_001 {

    public static void main(String[] args) {
        try {
            String tempFilePath = createTempFileWithUnicode();
            if (tempFilePath != null) {
                System.out.println("Temporary file created at: " + tempFilePath);
            }
        } catch (IOException e) {
            System.err.println("An error occurred: " + e.getMessage());
        }
    }

    public static String createTempFileWithUnicode() throws IOException {
        try {
            File tempFile = File.createTempFile("temp", ".txt");
            tempFile.deleteOnExit();

            String randomString = UUID.randomUUID().toString();

            try (FileOutputStream outputStream = new FileOutputStream(tempFile)) {
                outputStream.write(randomString.getBytes(StandardCharsets.UTF_8));
            }

            return tempFile.getAbsolutePath();
        } catch (IOException e) {
            throw new IOException("Failed to create temporary file: " + e.getMessage(), e);
        }
    }
}