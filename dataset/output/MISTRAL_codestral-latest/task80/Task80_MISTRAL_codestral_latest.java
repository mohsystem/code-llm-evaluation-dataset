// Java has built-in support for IPv6 sockets
import javax.net.ssl.*;
import java.net.*;

public class Task80_MISTRAL_codestral_latest {
    public static SSLSocket createSSLClientSocket(String host, int port) throws Exception {
        SSLSocketFactory factory = (SSLSocketFactory) SSLSocketFactory.getDefault();
        SSLSocket socket = (SSLSocket) factory.createSocket(host, port);
        socket.startHandshake();
        return socket;
    }
}