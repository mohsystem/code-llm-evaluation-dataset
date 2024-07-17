import javax.net.ssl.*;
import java.net.*;

public class SSLClientSocket {
    public static SSLSocket createSSLClientSocket(String host, int port) throws Exception {
        SSLSocketFactory sslSocketFactory = (SSLSocketFactory) SSLSocketFactory.getDefault();
        SSLSocket sslSocket = (SSLSocket) sslSocketFactory.createSocket(host, port);
        sslSocket.startHandshake();
        return sslSocket;
    }
}