import java.io.*;
import java.net.*;

public class Task96_OPENAI_gpt_4o {
    public static void main(String[] args) throws IOException {
        int port = 65432;
        ServerSocket serverSocket = new ServerSocket(port);
        System.out.println("Java server is listening on port " + port);
        
        Socket socket = serverSocket.accept();
        System.out.println("Connected to client");

        InputStream input = socket.getInputStream();
        OutputStream output = socket.getOutputStream();
        BufferedReader reader = new BufferedReader(new InputStreamReader(input));
        PrintWriter writer = new PrintWriter(output, true);

        String message;
        while ((message = reader.readLine()) != null) {
            writer.println(message);
        }
    }
}