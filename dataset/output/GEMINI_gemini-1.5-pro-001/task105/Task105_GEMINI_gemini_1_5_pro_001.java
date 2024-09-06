import javax.net.ssl.SSLSocket;
import javax.net.ssl.SSLSocketFactory;
import java.io.*;

public class Task105_GEMINI_gemini_1_5_pro_001 {
    public static void main(String[] args) {
        try {
            SSLSocketFactory factory = (SSLSocketFactory) SSLSocketFactory.getDefault();
            SSLSocket socket = (SSLSocket) factory.createSocket("www.google.com", 443);

            System.out.println("Connected to " + socket.getInetAddress().getHostName() + " on port " + socket.getPort());
            System.out.println("SSL/TLS version: " + socket.getSession().getProtocol());
            System.out.println("Cipher suite: " + socket.getSession().getCipherSuite());

            socket.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}