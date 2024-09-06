import java.net.InetAddress;
import java.net.InetSocketAddress;
import java.net.Socket;
import javax.net.ssl.SSLSocket;
import javax.net.ssl.SSLSocketFactory;

public class Task80_PERPLEXITY_llama_3_sonar_large_32k_chat {
    public static SSLSocket createSSLClientSocket(String host, int port) throws Exception {
        SSLSocketFactory factory = (SSLSocketFactory) SSLSocketFactory.getDefault();
        SSLSocket socket = (SSLSocket) factory.createSocket();
        InetAddress addr = InetAddress.getByName(host);
        socket.connect(new InetSocketAddress(addr, port));
        return socket;
    }
}