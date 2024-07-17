// Server side
import java.net.*;
import java.io.*;
import java.util.*;

class Server {
    public static void main(String[] args) throws IOException {
        ServerSocket serverSocket = new ServerSocket(8000);
        System.out.println("Server started. Listening for incoming connections...");
        Socket socket = serverSocket.accept();
        System.out.println("Incoming connection from " + socket.getInetAddress());
        BufferedReader in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
        PrintWriter out = new PrintWriter(socket.getOutputStream(), true);
        String inputLine;
        while ((inputLine = in.readLine()) != null) {
            String[] credentials = inputLine.split(",");
            String username = credentials[0];
            String password = credentials[1];
            if (authenticate(username, password)) {
                out.println("Login successful!");
            } else {
                out.println("Invalid credentials");
            }
        }
    }

    private static boolean authenticate(String username, String password) {
        // Implement authentication logic here
        // For demonstration purposes, assume authentication is successful
        return true;
    }
}

// Client side
import java.net.*;
import java.io.*;

class Client {
    public static void main(String[] args) throws IOException {
        Socket socket = new Socket("localhost", 8000);
        System.out.println("Connected to server");
        BufferedReader in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
        PrintWriter out = new PrintWriter(socket.getOutputStream(), true);
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter username: ");
        String username = scanner.nextLine();
        System.out.print("Enter password: ");
        String password = scanner.nextLine();
        out.println(username + "," + password);
        String response = in.readLine();
        System.out.println("Server response: " + response);
    }
}