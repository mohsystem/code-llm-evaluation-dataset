import org.apache.commons.net.ftp.FTP;
import org.apache.commons.net.ftp.FTPClient;
import java.io.FileOutputStream;
import java.io.IOException;

public class Task77_OPENAI_gpt_4o {
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

            try (FileOutputStream fos = new FileOutputStream(filename)) {
                ftpClient.retrieveFile(filename, fos);
            }
            ftpClient.logout();
        } catch (IOException ex) {
            ex.printStackTrace();
        } finally {
            try {
                if (ftpClient.isConnected()) {
                    ftpClient.disconnect();
                }
            } catch (IOException ex) {
                ex.printStackTrace();
            }
        }
    }
}