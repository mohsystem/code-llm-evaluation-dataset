import java.io.*;
import java.net.ServerSocket;
import java.net.Socket;

public class FileUploadServer {

    private static final int PORT = 1234;
    private static final String UPLOAD_DIR = "uploads/";

    public static void main(String[] args) {
        ServerSocket serverSocket = null;
        try {
            serverSocket = new ServerSocket(PORT);
            System.out.println("Server listening on port " + PORT);

            while (true) {
                Socket socket = serverSocket.accept();
                System.out.println("Client connected");

                InputStream inputStream = socket.getInputStream();
                DataInputStream dataInputStream = new DataInputStream(inputStream);

                String fileName = dataInputStream.readUTF();
                long fileSize = dataInputStream.readLong();
                
                File file = new File(UPLOAD_DIR + fileName);
                FileOutputStream fileOutputStream = new FileOutputStream(file);
                byte[] buffer = new byte[4096];

                int bytesRead;
                while (fileSize > 0 && (bytesRead = inputStream.read(buffer, 0, (int)Math.min(buffer.length, fileSize))) != -1) {
                    fileOutputStream.write(buffer, 0, bytesRead);
                    fileSize -= bytesRead;
                }

                fileOutputStream.close();
                System.out.println("File " + fileName + " received from client.");

                OutputStream outputStream = socket.getOutputStream();
                DataOutputStream dataOutputStream = new DataOutputStream(outputStream);
                dataOutputStream.writeUTF("File uploaded successfully");

                socket.close();
            }
        } catch (IOException e) {
            e.printStackTrace();
        } finally {
            if (serverSocket != null) {
                try {
                    serverSocket.close();
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
        }
    }
}