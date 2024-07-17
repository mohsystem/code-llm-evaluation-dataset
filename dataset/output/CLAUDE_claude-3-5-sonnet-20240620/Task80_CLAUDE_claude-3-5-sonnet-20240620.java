
import javax.net.ssl.*;
import java.net.*;

public class SSLClientSocket {
    public static SSLSocket createSSLSocket(String host, int port) throws Exception {
        SSLSocketFactory factory = (SSLSocketFactory) SSLSocketFactory.getDefault();
        InetAddress address = InetAddress.getByName(host);
        
        if (address instanceof Inet6Address) {
            return (SSLSocket) factory.createSocket(address, port);
        } else {
            throw new IllegalArgumentException("The provided host is not an IPv6 address");
        }
    }

    public static void main(String[] args) {
        try {
            SSLSocket socket = createSSLSocket("2001:db8::1", 443);
            System.out.println("SSL socket connected successfully");
            socket.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
