import java.io.IOException;
import java.net.InetSocketAddress;
import java.net.Socket;
import javax.net.ssl.SSLSocket;
import javax.net.ssl.SSLSocketFactory;

public class SSLClient {
    public static SSLSocket createSSLSocket(String host, int port) throws IOException {
        SSLSocketFactory factory = (SSLSocketFactory) SSLSocketFactory.getDefault();
        SSLSocket socket = (SSLSocket) factory.createSocket();
        socket.connect(new InetSocketAddress(host, port));
        return socket;
    }

    public static void main(String[] args) throws IOException {
        SSLSocket socket = createSSLSocket("::1", 443);
        System.out.println("Connected to " + socket.getInetAddress() + ":" + socket.getPort());
    }
}