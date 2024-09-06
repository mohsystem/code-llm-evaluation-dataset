import javax.net.ssl.SSLSocket;
import javax.net.ssl.SSLSocketFactory;
import java.io.IOException;

public class Task80_GEMINI_gemini_1_5_pro_001 {

    public static SSLSocket createSSLClientSocketIPv6(String hostname, int port) throws IOException {
        // Get the default SSL socket factory
        SSLSocketFactory sslSocketFactory = (SSLSocketFactory) SSLSocketFactory.getDefault();

        // Create an SSL socket using IPv6
        SSLSocket sslSocket = (SSLSocket) sslSocketFactory.createSocket(hostname, port);

        return sslSocket;
    }
}