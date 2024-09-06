// Java Code (Server)
import java.net.ServerSocket;
import java.net.Socket;
import java.io.*;

public class Task7_PERPLEXITY_llama_3_sonar_large_32k_chat {
    public static void main(String[] args) throws Exception {
        ServerSocket serverSocket = new ServerSocket(10000);
        System.out.println("Server started. Waiting for connections...");
        Socket connection = serverSocket.accept();
        System.out.println("Connected to " + connection.getInetAddress());

        BufferedReader reader = new BufferedReader(new InputStreamReader(connection.getInputStream()));
        PrintWriter writer = new PrintWriter(connection.getOutputStream(), true);

        while (true) {
            String data = reader.readLine();
            if (data.startsWith("LOGIN")) {
                String[] parts = data.split(" ");
                String username = parts[1];
                String password = parts[2];
                if (authenticate(username, password)) {
                    writer.println("LOGIN_SUCCESS");
                } else {
                    writer.println("LOGIN_FAILED");
                }
            } else {
                System.out.println("Received message: " + data);
                writer.println("Server received your message: " + data);
            }
        }
    }

    public static boolean authenticate(String username, String password) throws Exception {
        BufferedReader fileReader = new BufferedReader(new FileReader("users.txt"));
        String line;
        while ((line = fileReader.readLine()) != null) {
            String[] parts = line.split(":");
            if (parts[0].equals(username) && parts[1].equals(password)) {
                return true;
            }
        }
        return false;
    }
}