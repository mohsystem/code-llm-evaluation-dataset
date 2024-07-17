import org.apache.commons.net.ftp.FTP;
import org.apache.commons.net.ftp.FTPClient;

import java.io.FileOutputStream;
import java.io.IOException;

public class FTPDownload {
    public static void main(String[] args) {
        if(args.length < 4) {
            System.out.println("Usage: java FTPDownload <hostname> <username> <password> <remoteFilePath>");
            System.exit(1);
        }
        
        String server = args[0];
        int port = 21;
        String user = args[1];
        String pass = args[2];
        String remoteFile = args[3];
        
        FTPClient ftpClient = new FTPClient();
        
        try {
            ftpClient.connect(server, port);
            ftpClient.login(user, pass);
            ftpClient.enterLocalPassiveMode();
            ftpClient.setFileType(FTP.BINARY_FILE_TYPE);
            
            String remoteFilePath = remoteFile;
            String downloadFilePath = "./" + remoteFile.substring(remoteFile.lastIndexOf('/')+1);
            
            try (FileOutputStream fos = new FileOutputStream(downloadFilePath)) {
                boolean success = ftpClient.retrieveFile(remoteFilePath, fos);
                if (success) {
                    System.out.println("File has been downloaded successfully.");
                } else {
                    System.out.println("File download failed.");
                }
            }
            
            ftpClient.logout();
            ftpClient.disconnect();
        } catch (IOException ex) {
            ex.printStackTrace();
        }
    }
}