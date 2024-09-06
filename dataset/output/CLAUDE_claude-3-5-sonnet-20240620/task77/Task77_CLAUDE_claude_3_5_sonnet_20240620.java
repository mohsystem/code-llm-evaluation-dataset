
import java.io.*;
import org.apache.commons.net.ftp.FTPClient;

public class Task77_CLAUDE_claude_3_5_sonnet_20240620 {
    public static void main(String[] args) {
        if (args.length != 4) {
            System.out.println("Usage: java Task77_CLAUDE_claude_3_5_sonnet_20240620 <hostname> <username> <password> <filename>");
            System.exit(1);
        }

        String hostname = args[0];
        String username = args[1];
        String password = args[2];
        String filename = args[3];

        FTPClient ftpClient = new FTPClient();
        try {
            ftpClient.connect(hostname);
            ftpClient.login(username, password);
            
            File downloadFile = new File(filename);
            OutputStream outputStream = new BufferedOutputStream(new FileOutputStream(downloadFile));
            boolean success = ftpClient.retrieveFile(filename, outputStream);
            outputStream.close();

            if (success) {
                System.out.println("File " + filename + " downloaded successfully.");
            } else {
                System.out.println("Failed to download the file.");
            }

        } catch (IOException e) {
            System.out.println("An error occurred: " + e.getMessage());
        } finally {
            try {
                if (ftpClient.isConnected()) {
                    ftpClient.logout();
                    ftpClient.disconnect();
                }
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }
}
