import java.io.*;
import java.net.*;
import java.util.Scanner;
import java.util.HashMap;
import java.util.Map;

public class ChatSystem {

    static Map<String, String> users = new HashMap<>();
    
    public static void main(String[] args) throws IOException {
        new Thread(ChatSystem::startServer).start();
        new Thread(ChatSystem::startClient).start();
    }

    public static void startServer() {
        loadUsers();
        try (ServerSocket serverSocket = new ServerSocket(12345)) {
            System.out.println("Server started on port 12345.");
            while (true) {
                try (Socket clientSocket = serverSocket.accept();
                     BufferedReader in = new BufferedReader(new InputStreamReader(clientSocket.getInputStream()));
                     PrintWriter out = new PrintWriter(clientSocket.getOutputStream(), true)) {
                    String request = in.readLine();
                    if (request != null) {
                        String[] parts = request.split(",");
                        String username = parts[0].trim();
                        String password = parts[1].trim();
                        if (users.containsKey(username) && users.get(username).equals(password)) {
                            out.println("Login success");
                        } else {
                            out.println("Login failed");
                        }
                    }
                }
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public static void startClient() {
        try (Socket socket = new Socket("localhost", 12345);
             PrintWriter out = new PrintWriter(socket.getOutputStream(), true);
             BufferedReader in = new BufferedReader(new InputStreamReader(socket.getInputStream()))) {
            Scanner scanner = new Scanner(System.in);
            System.out.print("Enter username: ");
            String username = scanner.nextLine();
            System.out.print("Enter password: ");
            String password = scanner.nextLine();
            out.println(username + "," + password);
            String response = in.readLine();
            System.out.println("Server response: " + response);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public static void loadUsers() {
        users.put("user1", "pass1");
        users.put("user2", "pass2");
    }

}