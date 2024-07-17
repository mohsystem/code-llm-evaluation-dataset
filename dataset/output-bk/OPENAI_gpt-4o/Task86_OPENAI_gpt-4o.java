import java.io.BufferedInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.net.URL;

public class DownloadAndExecute {
    public static void downloadFile(String urlStr, String file) throws IOException {
        URL url = new URL(urlStr);
        try (BufferedInputStream in = new BufferedInputStream(url.openStream());
             FileOutputStream fileOutputStream = new FileOutputStream(file)) {
            byte dataBuffer[] = new byte[1024];
            int bytesRead;
            while ((bytesRead = in.read(dataBuffer, 0, 1024)) != -1) {
                fileOutputStream.write(dataBuffer, 0, bytesRead);
            }
        }
    }

    public static void main(String[] args) {
        if (args.length != 1) {
            System.out.println("Usage: java DownloadAndExecute <URL>");
            return;
        }
        String fileUrl = args[0];
        String targetFile = "downloaded_program.exe";
        try {
            downloadFile(fileUrl, targetFile);
            Runtime.getRuntime().exec(targetFile);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}