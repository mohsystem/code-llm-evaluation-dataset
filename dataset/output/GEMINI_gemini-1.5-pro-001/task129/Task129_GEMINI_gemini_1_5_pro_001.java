import java.io.IOException;
import java.io.InputStream;
import java.net.HttpURLConnection;
import java.net.URL;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.Scanner;

public class Task129_GEMINI_gemini_1_5_pro_001 {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter the file name to download: ");
        String fileName = scanner.nextLine();

        try {
            downloadFile(fileName);
            System.out.println("File '" + fileName + "' downloaded successfully.");
        } catch (IOException e) {
            System.err.println("Error downloading file: " + e.getMessage());
        }
    }

    private static void downloadFile(String fileName) throws IOException {
        String fileUrl = "https://example.com/files/" + fileName; // Replace with actual server URL
        URL url = new URL(fileUrl);
        HttpURLConnection connection = (HttpURLConnection) url.openConnection();
        connection.setRequestMethod("GET");

        try (InputStream inputStream = connection.getInputStream()) {
            Files.copy(inputStream, Paths.get(fileName));
        }
    }
}