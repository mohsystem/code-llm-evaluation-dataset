import javax.net.ssl.SSLSocket;
import javax.net.ssl.SSLSocketFactory;
import java.io.IOException;
import java.net.Inet6Address;
import java.net.InetAddress;
import java.net.Socket;

public class Task80_OPENAI_gpt_4o {
    public static Socket createSSLSocket(String host, int port) throws IOException {
        SSLSocketFactory factory = (SSLSocketFactory) SSLSocketFactory.getDefault();
        InetAddress address = Inet6Address.getByName(host);
        SSLSocket socket = (SSLSocket) factory.createSocket(address, port);
        return socket;
    }
}