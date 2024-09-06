
import javax.net.ssl.SSLSocket;
import javax.net.ssl.SSLSocketFactory;
import java.io.IOException;
import java.net.Inet6Address;

public class Task80_CLAUDE_claude_3_5_sonnet_20240620 {
    public static SSLSocket createSSLIPv6Socket(String host, int port) throws IOException {
        SSLSocketFactory factory = (SSLSocketFactory) SSLSocketFactory.getDefault();
        Inet6Address address = (Inet6Address) Inet6Address.getByName(host);
        return (SSLSocket) factory.createSocket(address, port);
    }

    public static void main(String[] args) {
        try {
            String host = "example.com";
            int port = 443;
            SSLSocket socket = createSSLIPv6Socket(host, port);
            // Use the socket here
            socket.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
