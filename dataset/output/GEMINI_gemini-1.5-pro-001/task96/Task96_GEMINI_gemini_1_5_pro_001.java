import java.net.*;
import java.io.*;

public class Task96_GEMINI_gemini_1_5_pro_001 {
    public static void main(String[] args) throws IOException {
        // Create a server socket
        ServerSocket serverSocket = new ServerSocket(5000);

        while (true) {
            // Accept a client connection
            Socket clientSocket = serverSocket.accept();

            // Create input and output streams for the connection
            DataInputStream input = new DataInputStream(clientSocket.getInputStream());
            DataOutputStream output = new DataOutputStream(clientSocket.getOutputStream());

            // Read the message from the client
            String message = input.readUTF();

            // Echo the message back to the client
            output.writeUTF(message);

            // Close the connection
            clientSocket.close();
        }
    }
}