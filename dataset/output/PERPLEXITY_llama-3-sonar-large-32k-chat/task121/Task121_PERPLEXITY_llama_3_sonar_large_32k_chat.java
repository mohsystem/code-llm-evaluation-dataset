import java.io.*;
import java.net.*;
import java.util.*;

public class Task121_PERPLEXITY_llama_3_sonar_large_32k_chat {
    public static void main(String[] args) throws IOException {
        ServerSocket serverSocket = new ServerSocket(8000);
        System.out.println("Server started. Listening for incoming connections...");

        Socket socket = serverSocket.accept();
        System.out.println("Incoming connection from " + socket.getInetAddress());

        BufferedReader reader = new BufferedReader(new InputStreamReader(socket.getInputStream()));
        PrintWriter writer = new PrintWriter(socket.getOutputStream(), true);

        String line;
        while ((line = reader.readLine()) != null) {
            if (line.startsWith("POST")) {
                String filename = line.split(" ")[1].split("/")[1];
                File file = new File(filename);
                FileOutputStream fos = new FileOutputStream(file);
                byte[] buffer = new byte[1024];
                int bytesRead;
                while ((bytesRead = socket.getInputStream().read(buffer)) != -1) {
                    fos.write(buffer, 0, bytesRead);
                }
                fos.close();
                System.out.println("File uploaded successfully!");
            }
        }
    }
}