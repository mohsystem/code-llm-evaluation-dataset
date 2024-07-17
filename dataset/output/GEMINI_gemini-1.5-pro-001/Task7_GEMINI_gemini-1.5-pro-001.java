import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.HashMap;
import java.util.Map;

public class ChatServer {

    private static final int PORT = 9001;
    private static final Map<String, String> userDatabase = new HashMap<>();

    static {
        userDatabase.put("user1", "pass1");
        userDatabase.put("user2", "pass2");
    }

    public static void main(String[] args) {
        try (ServerSocket serverSocket = new ServerSocket(PORT)) {
            System.out.println("Server started on port " + PORT);
            while (true) {
                Socket clientSocket = serverSocket.accept();
                new ClientHandler(clientSocket).start();
            }
        } catch (IOException e) {
            System.err.println("Error starting server: " + e.getMessage());
        }
    }

    private static class ClientHandler extends Thread {
        private final Socket clientSocket;

        public ClientHandler(Socket socket) {
            this.clientSocket = socket;
        }

        @Override
        public void run() {
            try (
                BufferedReader in = new BufferedReader(new InputStreamReader(clientSocket.getInputStream()));
                PrintWriter out = new PrintWriter(clientSocket.getOutputStream(), true)
            ) {
                String inputLine;
                while ((inputLine = in.readLine()) != null) {
                    String[] parts = inputLine.split(" ");
                    if (parts.length == 3 && parts[0].equals("LOGIN")) {
                        String username = parts[1];
                        String password = parts[2];
                        if (authenticate(username, password)) {
                            out.println("Welcome, " + username + "!");
                        } else {
                            out.println("Invalid username or password.");
                        }
                    }
                }
            } catch (IOException e) {
                System.err.println("Error handling client: " + e.getMessage());
            }
        }

        private boolean authenticate(String username, String password) {
            return userDatabase.containsKey(username) && userDatabase.get(username).equals(password);
        }
    }
}