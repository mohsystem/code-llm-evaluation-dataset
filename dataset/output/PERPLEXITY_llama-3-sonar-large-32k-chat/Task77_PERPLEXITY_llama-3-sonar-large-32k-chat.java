import java.io.FileOutputStream;
import java.io.IOException;
import java.net.SocketException;

import org.apache.commons.net.ftp.FTP;
import org.apache.commons.net.ftp.FTPClient;
import org.apache.commons.net.ftp.FTPFile;

public class FTPDownload {
    public static void main(String[] args) {
        String hostname = args[0];
        String username = args[1];
        String password = args[2];
        String filename = args[3];

        FTPClient ftpClient = new FTPClient();
        try {
            ftpClient.connect(hostname);
            ftpClient.login(username, password);
            ftpClient.enterLocalPassiveMode();
            ftpClient.setFileType(FTP.BINARY_FILE_TYPE);

            FTPFile[] files = ftpClient.listFiles();
            for (FTPFile file : files) {
                if (file.getName().equals(filename)) {
                    FileOutputStream fos = new FileOutputStream(file.getName());
                    ftpClient.retrieveFile(file.getName(), fos);
                    fos.close();
                    System.out.println("File downloaded successfully!");
                    return;
                }
            }
            System.out.println("File not found on the FTP server.");
        } catch (SocketException e) {
            System.out.println("Error connecting to the FTP server.");
        } catch (IOException e) {
            System.out.println("Error downloading the file.");
        } finally {
            try {
                ftpClient.logout();
                ftpClient.disconnect();
            } catch (IOException e) {
                System.out.println("Error logging out and disconnecting from the FTP server.");
            }
        }
    }
}