import java.io.*;
import java.net.*;
import org.apache.commons.net.ftp.*;

public class Task77_PERPLEXITY_llama_3_sonar_large_32k_chat {
    public static void main(String[] args) throws Exception {
        FTPClient ftp = new FTPClient();
        ftp.connect(args[0]);
        ftp.login(args[1], args[2]);
        ftp.enterLocalPassiveMode();
        FileOutputStream fos = new FileOutputStream(args[3]);
        ftp.retrieveFile(args[3], fos);
        fos.close();
        ftp.logout();
    }
}