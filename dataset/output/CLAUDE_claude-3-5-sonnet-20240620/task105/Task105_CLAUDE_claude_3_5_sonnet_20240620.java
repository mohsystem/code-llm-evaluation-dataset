
import javax.net.ssl.*;
import java.io.*;
import java.security.cert.X509Certificate;

public class Task105_CLAUDE_claude_3_5_sonnet_20240620 {
    public static void main(String[] args) {
        String host = "www.example.com";
        int port = 443;

        try {
            SSLContext context = SSLContext.getInstance("TLS");
            context.init(null, new TrustManager[]{new X509TrustManager() {
                public void checkClientTrusted(X509Certificate[] chain, String authType) {}
                public void checkServerTrusted(X509Certificate[] chain, String authType) {}
                public X509Certificate[] getAcceptedIssuers() { return new X509Certificate[0]; }
            }}, null);

            SSLSocketFactory factory = context.getSocketFactory();
            SSLSocket socket = (SSLSocket) factory.createSocket(host, port);

            socket.startHandshake();
            System.out.println("Connected to " + host + ":" + port);
            System.out.println("SSL version: " + socket.getSession().getProtocol());
            System.out.println("Cipher: " + socket.getSession().getCipherSuite());

            socket.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
