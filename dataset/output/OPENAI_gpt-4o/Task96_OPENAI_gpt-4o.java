import java.io.*;
import java.net.*;

public class MultiLangServer {
    public static void main(String[] args) throws IOException {
        // Java Code Block
        ServerSocket serverSocket = new ServerSocket(8080);
        System.out.println("Java Server listening on port 8080...");
        while (true) {
            Socket clientSocket = serverSocket.accept();
            BufferedReader in = new BufferedReader(new InputStreamReader(clientSocket.getInputStream()));
            PrintWriter out = new PrintWriter(clientSocket.getOutputStream(), true);

            String inputLine;
            while ((inputLine = in.readLine()) != null) {
                out.println("Echo: " + inputLine);
            }
        }
    }
}