import java.io.IOException;
import java.net.InetSocketAddress;
import java.nio.channels.SocketChannel;
import javax.net.ssl.*;

public class Main {
    public static void main(String[] args) {
        try {
            SSLSocket socket = createSSLClientSocket("hostname", 443);
            System.out.println("Connected to " + socket.getRemoteSocketAddress());
            socket.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    public static SSLSocket createSSLClientSocket(String host, int port) throws IOException {
        SSLSocketFactory factory = (SSLSocketFactory) SSLSocketFactory.getDefault();
        return (SSLSocket) factory.createSocket(InetSocketAddress.createUnresolved(host, port), port);
    }
}