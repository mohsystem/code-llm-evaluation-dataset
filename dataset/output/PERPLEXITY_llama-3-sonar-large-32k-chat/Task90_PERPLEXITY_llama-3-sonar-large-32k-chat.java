import java.io.*;
import java.net.*;
import java.util.*;

public class ChatServer {
    private ServerSocket serverSocket;
    private List<PrintWriter> writers = new ArrayList<>();

    public ChatServer(int port) throws IOException {
        serverSocket = new ServerSocket(port);
        System.out.println("Chat server is running...");
    }

    public void run() {
        while (true) {
            Socket socket = serverSocket.accept();
            System.out.println("New client connected");
            PrintWriter writer = new PrintWriter(socket.getOutputStream(), true);
            writers.add(writer);
            new Thread(new Handler(socket)).start();
        }
    }

    private class Handler implements Runnable {
        private Socket socket;
        private BufferedReader reader;

        public Handler(Socket socket) {
            this.socket = socket;
            try {
                reader = new BufferedReader(new InputStreamReader(socket.getInputStream()));
            } catch (IOException e) {
                e.printStackTrace();
            }
        }

        public void run() {
            try {
                String message;
                while ((message = reader.readLine()) != null) {
                    System.out.println("Received message: " + message);
                    broadcast(message);
                }
            } catch (IOException e) {
                e.printStackTrace();
            } finally {
                try {
                    socket.close();
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
        }

        private void broadcast(String message) {
            for (PrintWriter writer : writers) {
                writer.println(message);
            }
        }
    }

    public static void main(String[] args) throws IOException {
        ChatServer server = new ChatServer(8000);
        server.run();
    }
}