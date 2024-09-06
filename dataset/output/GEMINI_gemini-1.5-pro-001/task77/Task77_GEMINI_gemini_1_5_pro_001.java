import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import org.apache.commons.net.ftp.FTPClient;

public class Task77_GEMINI_gemini_1_5_pro_001 {
    public static void main(String[] args) {
        if (args.length != 4) {
            System.out.println("Usage: java Task77_GEMINI_gemini_1_5_pro_001 <hostname> <username> <password> <remote_filename>");
            return;
        }

        String hostname = args[0];
        String username = args[1];
        String password = args[2];
        String remoteFilename = args[3];

        try (FTPClient ftpClient = new FTPClient()) {
            ftpClient.connect(hostname);
            ftpClient.login(username, password);

            try (InputStream inputStream = ftpClient.retrieveFileStream(remoteFilename);
                 FileOutputStream fileOutputStream = new FileOutputStream(remoteFilename)) {
                byte[] buffer = new byte[1024];
                int bytesRead;
                while ((bytesRead = inputStream.read(buffer)) != -1) {
                    fileOutputStream.write(buffer, 0, bytesRead);
                }
            }

            boolean success = ftpClient.completePendingCommand();
            if (success) {
                System.out.println("File '" + remoteFilename + "' downloaded successfully.");
            } else {
                System.err.println("Error downloading file: " + ftpClient.getReplyString());
            }

        } catch (IOException e) {
            System.err.println("FTP error: " + e.getMessage());
        }
    }
}