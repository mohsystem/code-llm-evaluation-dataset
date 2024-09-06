import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.HashMap;
import java.util.Map;

public class Task108_GEMINI_gemini_1_5_pro_001 {
    private int port;
    private Map<String, Object> objects;

    public Task108_GEMINI_gemini_1_5_pro_001(int port) {
        this.port = port;
        this.objects = new HashMap<>();
    }

    public void start() throws IOException {
        ServerSocket serverSocket = new ServerSocket(port);
        System.out.println("Server started on port " + port);

        while (true) {
            Socket clientSocket = serverSocket.accept();
            System.out.println("Client connected from " + clientSocket.getInetAddress());
            handleClient(clientSocket);
        }
    }

    private void handleClient(Socket clientSocket) throws IOException {
        try (ObjectOutputStream out = new ObjectOutputStream(clientSocket.getOutputStream());
             ObjectInputStream in = new ObjectInputStream(clientSocket.getInputStream())) {

            while (true) {
                try {
                    Object[] request = (Object[]) in.readObject();
                    String command = (String) request[0];

                    if (command.equals("CREATE")) {
                        String objectId = (String) request[1];
                        Object objectData = request[2];
                        objects.put(objectId, objectData);
                    } else if (command.equals("GET")) {
                        String objectId = (String) request[1];
                        out.writeObject(objects.get(objectId));
                    } else if (command.equals("SET")) {
                        String objectId = (String) request[1];
                        String attribute = (String) request[2];
                        Object value = request[3];
                        Object object = objects.get(objectId);
                        object.getClass().getField(attribute).set(object, value);
                    } else if (command.equals("CALL")) {
                        String objectId = (String) request[1];
                        String method = (String) request[2];
                        Object[] methodArgs = (Object[]) request[3];
                        Object object = objects.get(objectId);
                        Object result = object.getClass().getMethod(method, methodArgs.getClass()).invoke(object, methodArgs);
                        out.writeObject(result);
                    }
                } catch (Exception e) {
                    System.err.println("Error handling client request: " + e.getMessage());
                    break;
                }
            }
        } catch (IOException e) {
            System.err.println("Error handling client connection: " + e.getMessage());
        } finally {
            clientSocket.close();
        }
    }

    public static void main(String[] args) throws IOException {
        Task108_GEMINI_gemini_1_5_pro_001 server = new Task108_GEMINI_gemini_1_5_pro_001(5000);
        server.start();
    }
}