import java.io.*;
import java.net.*;
import java.util.*;

public class Task7_GEMINI_gemini_1_5_pro_001 {

    private static final int PORT = 65432;
    private static Set<ClientHandler> clients = new HashSet<>();
    private static Map<String, String> users = new HashMap<>();

    public static void main(String[] args) {
        loadUsers();
        try (ServerSocket serverSocket = new ServerSocket(PORT)) {
            System.out.println("Server started on port " + PORT);
            while (true) {
                Socket clientSocket = serverSocket.accept();
                System.out.println("New client connected: " + clientSocket);
                ClientHandler clientHandler = new ClientHandler(clientSocket);
                clients.add(clientHandler);
                new Thread(clientHandler).start();
            }
        } catch (IOException e) {
            System.err.println("Error starting server: " + e.getMessage());
        }
    }

    private static void loadUsers() {
        try (BufferedReader reader = new BufferedReader(new FileReader("users.txt"))) {
            String line;
            while ((line = reader.readLine()) != null) {
                String[] parts = line.split(":");
                users.put(parts[0], parts[1]);
            }
        } catch (IOException e) {
            System.err.println("Error loading users: " + e.getMessage());
        }
    }

    public static void broadcast(String message, ClientHandler sender) {
        for (ClientHandler client : clients) {
            if (client != sender) {
                client.sendMessage(message);
            }
        }
    }

    public static void removeClient(ClientHandler client) {
        clients.remove(client);
        broadcast("User " + client.getUsername() + " has left the chat.", null);
    }

    private static class ClientHandler implements Runnable {
        private Socket clientSocket;
        private String username;
        private BufferedReader in;
        private PrintWriter out;

        public ClientHandler(Socket clientSocket) {
            this.clientSocket = clientSocket;
            try {
                this.in = new BufferedReader(new InputStreamReader(clientSocket.getInputStream()));
                this.out = new PrintWriter(clientSocket.getOutputStream(), true);
            } catch (IOException e) {
                System.err.println("Error getting client streams: " + e.getMessage());
            }
        }

        public String getUsername() {
            return username;
        }

        @Override
        public void run() {
            try {
                // Authentication
                while (username == null) {
                    out.println("Enter username:");
                    String username = in.readLine();
                    out.println("Enter password:");
                    String password = in.readLine();
                    if (users.containsKey(username) && users.get(username).equals(password)) {
                        this.username = username;
                        out.println("Login successful!");
                        broadcast("User " + username + " has joined the chat.", this);
                    } else {
                        out.println("Invalid credentials!");
                    }
                }

                // Chat loop
                String message;
                while ((message = in.readLine()) != null) {
                    broadcast(username + ": " + message, this);
                }
            } catch (IOException e) {
                System.err.println("Error handling client: " + e.getMessage());
            } finally {
                try {
                    clientSocket.close();
                } catch (IOException e) {
                    System.err.println("Error closing client socket: " + e.getMessage());
                }
                removeClient(this);
            }
        }

        public void sendMessage(String message) {
            out.println(message);
        }
    }
}