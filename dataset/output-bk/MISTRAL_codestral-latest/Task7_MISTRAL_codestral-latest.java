// Client
import java.io.*;
import java.net.*;

public class ChatClient {
    public static void main(String[] args) throws IOException {
        Socket socket = new Socket("localhost", 4999);
        DataOutputStream out = new DataOutputStream(socket.getOutputStream());
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));

        System.out.println("Enter username: ");
        String username = in.readLine();
        System.out.println("Enter password: ");
        String password = in.readLine();

        out.writeUTF(username + "," + password);
        socket.close();
    }
}

// Server
import java.io.*;
import java.net.*;

public class ChatServer {
    public static void main(String[] args) throws IOException {
        ServerSocket serverSocket = new ServerSocket(4999);
        Socket socket = serverSocket.accept();
        DataInputStream in = new DataInputStream(socket.getInputStream());

        String input = in.readUTF();
        String[] credentials = input.split(",");
        // Authenticate credentials here

        socket.close();
        serverSocket.close();
    }
}