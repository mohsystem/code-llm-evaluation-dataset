import java.io.BufferedInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.net.URL;
import java.nio.file.Paths;
import java.util.concurrent.Executors;

public class Task86_OPENAI_gpt_4o {
    public static void main(String[] args) throws IOException {
        String fileUrl = "http://example.com/program.exe";
        String fileName = "downloaded_program.exe";
        
        try (BufferedInputStream in = new BufferedInputStream(new URL(fileUrl).openStream());
             FileOutputStream fileOutputStream = new FileOutputStream(fileName)) {
            byte dataBuffer[] = new byte[1024];
            int bytesRead;
            while ((bytesRead = in.read(dataBuffer, 0, 1024)) != -1) {
                fileOutputStream.write(dataBuffer, 0, bytesRead);
            }
        }
        
        ProcessBuilder processBuilder = new ProcessBuilder(Paths.get(fileName).toAbsolutePath().toString());
        processBuilder.inheritIO();
        try {
            Process process = processBuilder.start();
            Executors.newSingleThreadExecutor().submit(() -> {
                try {
                    process.waitFor();
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            });
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}