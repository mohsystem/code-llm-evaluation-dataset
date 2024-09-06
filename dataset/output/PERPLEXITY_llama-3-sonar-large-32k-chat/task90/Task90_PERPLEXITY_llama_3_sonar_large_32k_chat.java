import java.io.*;
import java.net.*;
import java.util.*;

public class Task90_PERPLEXITY_llama_3_sonar_large_32k_chat {
    private static final int PORT = 9090;
    private static final String HOST = "127.0.0.1";
    private static ServerSocket serverSocket;
    private static Socket socket;
    private static ArrayList<Socket> clients = new ArrayList<>();
    private static ArrayList<String> nicknames = new ArrayList<>();

    public static void main(String[] args) throws IOException {
        serverSocket = new ServerSocket(PORT);
        System.out.println("Server Started!");

        while (true) {
            socket = serverSocket.accept();
            System.out.println("Connected with " + socket.getInetAddress());

            PrintWriter out = new PrintWriter(socket.getOutputStream(), true);
            BufferedReader in = new BufferedReader(new InputStreamReader(socket.getInputStream()));

            out.println("NICK");
            String nickname = in.readLine();
            nicknames.add(nickname);
            clients.add(socket);

            System.out.println("Nickname of the client is " + nickname + "!");
            broadcast(nickname + " joined the chat!");

            new Thread(new HandleClient(socket, in, out)).start();
        }
    }

    private static void broadcast(String message) {
        for (Socket client : clients) {
            try {
                PrintWriter out = new PrintWriter(client.getOutputStream(), true);
                out.println(message);
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }

    private static class HandleClient implements Runnable {
        private Socket socket;
        private BufferedReader in;
        private PrintWriter out;

        public HandleClient(Socket socket, BufferedReader in, PrintWriter out) {
            this.socket = socket;
            this.in = in;
            this.out = out;
        }

        @Override
        public void run() {
            try {
                while (true) {
                    String message = in.readLine();
                    broadcast(message);
                }
            } catch (IOException e) {
                int index = clients.indexOf(socket);
                clients.remove(socket);
                socket.close();
                String nickname = nicknames.get(index);
                broadcast(nickname + " left the chat!");
                nicknames.remove(nickname);
            }
        }
    }
}