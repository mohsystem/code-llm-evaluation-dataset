import java.io.FileOutputStream;
import java.io.IOException;
import java.net.URL;
import java.nio.channels.Channels;
import java.nio.channels.ReadableByteChannel;

public class Task86_GEMINI_gemini_1_5_pro_001 {

    public static void main(String[] args) {
        if (args.length == 0) {
            System.out.println("Please provide the URL of the EXE file as a command-line argument.");
            return;
        }

        String url = args[0];

        try {
            downloadFile(url, "downloaded_file.exe");
            runExe("downloaded_file.exe");
        } catch (IOException e) {
            System.err.println("An error occurred: " + e.getMessage());
        }
    }

    private static void downloadFile(String url, String fileName) throws IOException {
        try (ReadableByteChannel rbc = Channels.newChannel(new URL(url).openStream());
             FileOutputStream fos = new FileOutputStream(fileName)) {
            fos.getChannel().transferFrom(rbc, 0, Long.MAX_VALUE);
        }
    }

    private static void runExe(String fileName) throws IOException {
        ProcessBuilder processBuilder = new ProcessBuilder(fileName);
        processBuilder.inheritIO(); // Inherit input/output streams
        try {
            Process process = processBuilder.start();
            process.waitFor(); // Wait for the process to finish
        } catch (InterruptedException e) {
            Thread.currentThread().interrupt();
            throw new IOException("Process interrupted", e);
        }
    }
}