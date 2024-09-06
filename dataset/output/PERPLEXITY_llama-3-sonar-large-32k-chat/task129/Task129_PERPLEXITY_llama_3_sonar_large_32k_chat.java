import java.io.*;
import java.net.*;
import java.util.Scanner;

public class Task129_PERPLEXITY_llama_3_sonar_large_32k_chat {
    public static void retrieveFile(String fileName) throws IOException {
        Socket clientSocket = new Socket("localhost", 12345);
        OutputStream outputStream = clientSocket.getOutputStream();
        outputStream.write(fileName.getBytes());
        InputStream inputStream = clientSocket.getInputStream();
        byte[] buffer = new byte[1024];
        int bytesRead;
        if (inputStream.read(buffer) == -1) {
            System.out.println("File not found on the server");
        } else {
            FileOutputStream fileOutputStream = new FileOutputStream(fileName);
            while ((bytesRead = inputStream.read(buffer)) != -1) {
                fileOutputStream.write(buffer, 0, bytesRead);
            }
            fileOutputStream.close();
        }
        clientSocket.close();
    }

    public static void main(String[] args) throws IOException {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter the file name: ");
        String fileName = scanner.nextLine();
        retrieveFile(fileName);
    }
}