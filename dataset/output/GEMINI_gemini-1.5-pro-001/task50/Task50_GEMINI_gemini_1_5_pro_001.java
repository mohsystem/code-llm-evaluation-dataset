import java.io.BufferedInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;

public class Task50_GEMINI_gemini_1_5_pro_001 {

    public static void main(String[] args) throws IOException {
        int port = 65432; // Choose a port number

        try (ServerSocket serverSocket = new ServerSocket(port)) {
            System.out.println("Server started on port " + port);

            while (true) {
                Socket clientSocket = serverSocket.accept();
                System.out.println("Client connected: " + clientSocket.getInetAddress());

                handleClient(clientSocket);
            }
        }
    }

    private static void handleClient(Socket clientSocket) throws IOException {
        try (BufferedInputStream in = new BufferedInputStream(clientSocket.getInputStream())) {
            byte[] buffer = new byte[1024];
            int bytesRead;

            // Read filename and filesize
            String filename = readLine(in);
            long filesize = Long.parseLong(readLine(in));

            System.out.println("Receiving file: " + filename + " (" + filesize + " bytes)");

            try (FileOutputStream fileOutputStream = new FileOutputStream(filename)) {
                long totalBytesRead = 0;
                while (totalBytesRead < filesize && (bytesRead = in.read(buffer, 0, Math.min(buffer.length, (int) (filesize - totalBytesRead)))) != -1) {
                    fileOutputStream.write(buffer, 0, bytesRead);
                    totalBytesRead += bytesRead;
                }
            }

            System.out.println(filename + " uploaded successfully!");
        } finally {
            clientSocket.close();
        }
    }

    private static String readLine(BufferedInputStream in) throws IOException {
        StringBuilder sb = new StringBuilder();
        int c;
        while ((c = in.read()) != -1 && c != '\n') {
            sb.append((char) c);
        }
        return sb.toString().trim();
    }
}