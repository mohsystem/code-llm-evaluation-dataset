import java.io.FileOutputStream;
import java.io.IOException;
import org.apache.commons.net.ftp.FTPClient;

public class FTPFileDownloader {

    public static void main(String[] args) {
        if (args.length != 4) {
            System.err.println("Usage: java FTPFileDownloader <hostname> <username> <password> <filename>");
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
            ftpClient.enterLocalPassiveMode();

            FileOutputStream fos = new FileOutputStream(filename);
            ftpClient.retrieveFile(filename, fos);

            fos.close();
            ftpClient.disconnect();

            System.out.println("File downloaded successfully.");

        } catch (IOException e) {
            System.err.println("Error downloading file: " + e.getMessage());
            e.printStackTrace();
        }
    }
}