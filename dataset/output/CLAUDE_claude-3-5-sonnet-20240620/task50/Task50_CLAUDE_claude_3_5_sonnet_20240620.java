
import java.io.*;
import java.net.*;

public class Task50_CLAUDE_claude_3_5_sonnet_20240620 {
    public static void main(String[] args) throws IOException {
        ServerSocket serverSocket = new ServerSocket(8080);
        System.out.println("Server is listening on port 8080");

        while (true) {
            Socket clientSocket = serverSocket.accept();
            System.out.println("Client connected: " + clientSocket.getInetAddress());

            InputStream inputStream = clientSocket.getInputStream();
            BufferedReader reader = new BufferedReader(new InputStreamReader(inputStream));
            
            String fileName = reader.readLine();
            long fileSize = Long.parseLong(reader.readLine());

            FileOutputStream fileOutputStream = new FileOutputStream("uploads/" + fileName);
            byte[] buffer = new byte[4096];
            int bytesRead;
            long totalBytesRead = 0;

            while (totalBytesRead < fileSize && (bytesRead = inputStream.read(buffer)) != -1) {
                fileOutputStream.write(buffer, 0, bytesRead);
                totalBytesRead += bytesRead;
            }

            fileOutputStream.close();
            
            PrintWriter writer = new PrintWriter(clientSocket.getOutputStream(), true);
            writer.println("File uploaded successfully");

            clientSocket.close();
        }
    }
}
