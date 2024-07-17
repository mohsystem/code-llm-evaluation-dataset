import java.io.*;
import java.net.*;
import java.util.HashMap;

public class Server {
    private static HashMap<String, Object> objects = new HashMap<>();

    public static void main(String[] args) {
        try (ServerSocket serverSocket = new ServerSocket(7896)) {
            while (true) {
                new ClientHandler(serverSocket.accept()).start();
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    private static class ClientHandler extends Thread {
        private Socket socket;
        private ObjectInputStream in;
        private ObjectOutputStream out;

        public ClientHandler(Socket socket) {
            this.socket = socket;
        }

        public void run() {
            try {
                in = new ObjectInputStream(socket.getInputStream());
                out = new ObjectOutputStream(socket.getOutputStream());

                String action = (String) in.readObject();
                String key = (String) in.readObject();
                Object value = in.readObject();

                if ("put".equals(action)) {
                    objects.put(key, value);
                    out.writeObject("Success");
                } else if ("get".equals(action)) {
                    out.writeObject(objects.get(key));
                }

                in.close();
                out.close();
                socket.close();
            } catch (IOException | ClassNotFoundException e) {
                e.printStackTrace();
            }
        }
    }
}