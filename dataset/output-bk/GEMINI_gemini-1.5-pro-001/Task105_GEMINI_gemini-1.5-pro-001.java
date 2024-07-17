import javax.net.ssl.SSLSocket;
import javax.net.ssl.SSLSocketFactory;
import java.io.IOException;

public class SecureConnection {

    public static void main(String[] args) {
        if (args.length != 2) {
            System.err.println("Usage: java SecureConnection <hostname> <port>");
            return;
        }

        String hostname = args[0];
        int port = Integer.parseInt(args[1]);

        try {
            SSLSocketFactory factory = (SSLSocketFactory) SSLSocketFactory.getDefault();
            SSLSocket socket = (SSLSocket) factory.createSocket(hostname, port);

            System.out.println("Secure connection established:");
            System.out.println("Socket: " + socket);
            System.out.println("Session: " + socket.getSession());

            socket.close();

        } catch (IOException e) {
            System.err.println("Error creating secure connection: " + e.getMessage());
        }
    }
}