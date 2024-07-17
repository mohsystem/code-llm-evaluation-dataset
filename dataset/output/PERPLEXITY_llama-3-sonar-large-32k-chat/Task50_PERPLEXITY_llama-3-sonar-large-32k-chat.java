import java.io.*;
import java.net.*;

public class FileServer {
    public static void main(String[] args) throws IOException {
        ServerSocket serverSocket = new ServerSocket(8000);
        System.out.println("Server started. Listening for incoming connections...");
        
        Socket socket = serverSocket.accept();
        System.out.println("Incoming connection from " + socket.getInetAddress());
        
        BufferedInputStream in = new BufferedInputStream(socket.getInputStream());
        FileOutputStream out = new FileOutputStream("uploaded_file");
        
        byte[] buffer = new byte[1024];
        int bytesRead;
        while ((bytesRead = in.read(buffer)) != -1) {
            out.write(buffer, 0, bytesRead);
        }
        
        out.close();
        in.close();
        socket.close();
        
        System.out.println("File uploaded successfully!");
    }
}