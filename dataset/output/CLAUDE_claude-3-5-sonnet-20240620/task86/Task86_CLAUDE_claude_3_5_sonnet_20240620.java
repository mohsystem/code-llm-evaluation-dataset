
import java.io.*;
import java.net.*;

public class Task86_CLAUDE_claude_3_5_sonnet_20240620 {
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        System.out.print("Enter the URL of the EXE file: ");
        String url = reader.readLine();

        String fileName = url.substring(url.lastIndexOf('/') + 1);

        // Download the file
        try (InputStream in = new URL(url).openStream();
             FileOutputStream fos = new FileOutputStream(fileName)) {
            byte[] buffer = new byte[1024];
            int bytesRead;
            while ((bytesRead = in.read(buffer)) != -1) {
                fos.write(buffer, 0, bytesRead);
            }
        }

        // Execute the file
        if (System.getProperty("os.name").toLowerCase().contains("win")) {
            Runtime.getRuntime().exec(fileName);
        } else {
            Runtime.getRuntime().exec("chmod +x " + fileName);
            Runtime.getRuntime().exec("./" + fileName);
        }
    }
}
