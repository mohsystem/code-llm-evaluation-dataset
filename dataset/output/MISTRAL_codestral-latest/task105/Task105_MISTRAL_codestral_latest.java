import javax.net.ssl.SSLSocket;
import javax.net.ssl.SSLSocketFactory;
import java.io.IOException;

public class Task105_MISTRAL_codestral_latest {
    public static void main(String[] args) throws IOException {
        // Define the remote server and port
        String server = "www.example.com";
        int port = 443;

        // Create a SSL socket factory
        SSLSocketFactory factory = (SSLSocketFactory) SSLSocketFactory.getDefault();

        // Create a SSL socket
        SSLSocket socket = (SSLSocket) factory.createSocket(server, port);

        // Start the handshake
        socket.startHandshake();

        // Now you can use the socket to communicate with the server securely
    }
}