import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.ArrayList;
import java.util.List;

public class RemoteObjectServer {

    private static final int PORT = 65432;
    private static List<DataObject> objects = new ArrayList<>();

    public static void main(String[] args) throws IOException, ClassNotFoundException {
        objects.add(new DataObject(10));
        ServerSocket serverSocket = new ServerSocket(PORT);
        System.out.println("Server started on port " + PORT);

        while (true) {
            Socket clientSocket = serverSocket.accept();
            System.out.println("Client connected: " + clientSocket.getInetAddress());
            new ClientHandler(clientSocket).start();
        }
    }

    private static class ClientHandler extends Thread {
        private final Socket clientSocket;
        private ObjectInputStream in;
        private ObjectOutputStream out;

        public ClientHandler(Socket socket) {
            this.clientSocket = socket;
        }

        @Override
        public void run() {
            try {
                in = new ObjectInputStream(clientSocket.getInputStream());
                out = new ObjectOutputStream(clientSocket.getOutputStream());

                while (true) {
                    String request = (String) in.readObject();
                    String[] parts = request.split(" ", 2);
                    String command = parts[0];

                    if (command.equals("GET")) {
                        int index = Integer.parseInt(parts[1]);
                        sendResponse(objects.get(index).getValue());
                    } else if (command.equals("SET")) {
                        String[] setParts = parts[1].split(" ", 2);
                        int index = Integer.parseInt(setParts[0]);
                        int newValue = Integer.parseInt(setParts[1]);
                        objects.get(index).setValue(newValue);
                        sendResponse("Value updated");
                    } else {
                        sendResponse("Invalid command");
                    }
                }
            } catch (IOException | ClassNotFoundException e) {
                System.out.println("Error handling client: " + e.getMessage());
            } finally {
                try {
                    clientSocket.close();
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
        }

        private void sendResponse(Object response) throws IOException {
            out.writeObject(response);
        }
    }
}

class DataObject {
    private int value;

    public DataObject(int value) {
        this.value = value;
    }

    public int getValue() {
        return value;
    }

    public void setValue(int value) {
        this.value = value;
    }
}