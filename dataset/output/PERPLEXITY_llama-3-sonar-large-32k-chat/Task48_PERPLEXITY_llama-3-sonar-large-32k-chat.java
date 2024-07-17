import java.net.*;
import java.io.*;
import java.util.*;

class Server {
    static ServerSocket serverSocket;
    static ArrayList<PrintWriter> clients = new ArrayList<>();

    public static void main(String[] args) throws IOException {
        serverSocket = new ServerSocket(8000);
        System.out.println("Server started. Waiting for clients...");

        while (true) {
            Socket socket = serverSocket.accept();
            System.out.println("Client connected");

            PrintWriter out = new PrintWriter(socket.getOutputStream(), true);
            clients.add(out);

            BufferedReader in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
            String inputLine;

            while ((inputLine = in.readLine()) != null) {
                System.out.println("Received from client: " + inputLine);
                broadcast(inputLine);
            }
        }
    }

    static void broadcast(String message) {
        for (PrintWriter out : clients) {
            out.println(message);
        }
    }
}

class Client {
    static Socket socket;
    static BufferedReader in;
    static PrintWriter out;

    public static void main(String[] args) throws IOException {
        socket = new Socket("localhost", 8000);
        in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
        out = new PrintWriter(socket.getOutputStream(), true);

        new Thread(new ReceiveThread()).start();

        Scanner scanner = new Scanner(System.in);
        while (true) {
            String message = scanner.nextLine();
            out.println(message);
        }
    }

    static class ReceiveThread extends Thread {
        @Override
        public void run() {
            String inputLine;
            try {
                while ((inputLine = in.readLine()) != null) {
                    System.out.println("Received from server: " + inputLine);
                }
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }
}