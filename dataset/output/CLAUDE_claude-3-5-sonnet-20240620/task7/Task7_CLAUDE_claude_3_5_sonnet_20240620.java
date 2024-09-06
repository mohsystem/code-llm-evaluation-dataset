
import java.io.*;
import java.net.*;
import java.util.*;
import org.json.simple.*;
import org.json.simple.parser.*;

// Server
class Server {
    private ServerSocket serverSocket;
    private List<Socket> clients = new ArrayList<>();

    public Server(int port) throws IOException {
        serverSocket = new ServerSocket(port);
    }

    public void start() throws IOException {
        System.out.println("Server listening on port " + serverSocket.getLocalPort());
        while (true) {
            Socket clientSocket = serverSocket.accept();
            clients.add(clientSocket);
            new Thread(new ClientHandler(clientSocket)).start();
        }
    }

    private class ClientHandler implements Runnable {
        private Socket clientSocket;
        private BufferedReader in;
        private PrintWriter out;

        public ClientHandler(Socket socket) throws IOException {
            this.clientSocket = socket;
            in = new BufferedReader(new InputStreamReader(clientSocket.getInputStream()));
            out = new PrintWriter(clientSocket.getOutputStream(), true);
        }

        public void run() {
            try {
                String inputLine;
                while ((inputLine = in.readLine()) != null) {
                    JSONObject request = (JSONObject) new JSONParser().parse(inputLine);
                    if (request.get("action").equals("login")) {
                        JSONObject response = authenticate((String) request.get("username"), (String) request.get("password"));
                        out.println(response.toJSONString());
                    }
                }
            } catch (IOException | ParseException e) {
                e.printStackTrace();
            } finally {
                try {
                    clientSocket.close();
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
        }

        private JSONObject authenticate(String username, String password) {
            JSONObject response = new JSONObject();
            try (BufferedReader fileReader = new BufferedReader(new FileReader("users.txt"))) {
                String line;
                while ((line = fileReader.readLine()) != null) {
                    String[] parts = line.split(":");
                    if (parts[0].equals(username) && parts[1].equals(password)) {
                        response.put("status", "success");
                        response.put("message", "Login successful");
                        return response;
                    }
                }
            } catch (IOException e) {
                e.printStackTrace();
            }
            response.put("status", "failure");
            response.put("message", "Invalid credentials");
            return response;
        }
    }
}

// Client
class Client {
    private Socket clientSocket;
    private PrintWriter out;
    private BufferedReader in;

    public void startConnection(String ip, int port) throws IOException {
        clientSocket = new Socket(ip, port);
        out = new PrintWriter(clientSocket.getOutputStream(), true);
        in = new BufferedReader(new InputStreamReader(clientSocket.getInputStream()));
    }

    public void login() throws IOException, ParseException {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter username: ");
        String username = scanner.nextLine();
        System.out.print("Enter password: ");
        String password = scanner.nextLine();

        JSONObject request = new JSONObject();
        request.put("action", "login");
        request.put("username", username);
        request.put("password", password);

        out.println(request.toJSONString());
        String response = in.readLine();
        JSONObject jsonResponse = (JSONObject) new JSONParser().parse(response);
        System.out.println(jsonResponse.get("message"));
    }

    public void stopConnection() throws IOException {
        in.close();
        out.close();
        clientSocket.close();
    }
}

public class Task7_CLAUDE_claude_3_5_sonnet_20240620 {
    public static void main(String[] args) throws IOException, ParseException {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter 's' for server, 'c' for client: ");
        String choice = scanner.nextLine().toLowerCase();

        if (choice.equals("s")) {
            Server server = new Server(5000);
            server.start();
        } else if (choice.equals("c")) {
            Client client = new Client();
            client.startConnection("localhost", 5000);
            client.login();
            client.stopConnection();
        } else {
            System.out.println("Invalid choice");
        }
    }
}
