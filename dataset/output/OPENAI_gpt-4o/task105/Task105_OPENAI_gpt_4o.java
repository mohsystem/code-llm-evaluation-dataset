import javax.net.ssl.SSLSocketFactory;
import javax.net.ssl.SSLSocket;
import java.io.IOException;

public class Task105_OPENAI_gpt_4o {
    public static void main(String[] args) {
        String host = "example.com";
        int port = 443;
        try {
            SSLSocketFactory factory = (SSLSocketFactory) SSLSocketFactory.getDefault();
            SSLSocket socket = (SSLSocket) factory.createSocket(host, port);
            socket.startHandshake();
            System.out.println(socket.getSession().getProtocol());
            socket.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}