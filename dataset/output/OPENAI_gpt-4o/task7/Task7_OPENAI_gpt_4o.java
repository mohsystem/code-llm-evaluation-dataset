// Java - Client
import java.io.*;
import java.net.*;
import java.util.Scanner;

public class Task7_OPENAI_gpt_4o {
    public static void main(String[] args) {
        String serverAddress = "127.0.0.1";
        int port = 12345;
        
        try (Socket socket = new Socket(serverAddress, port)) {
            PrintWriter out = new PrintWriter(socket.getOutputStream(), true);
            BufferedReader in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
            
            Scanner scanner = new Scanner(System.in);
            System.out.print("Username: ");
            String username = scanner.nextLine();
            System.out.print("Password: ");
            String password = scanner.nextLine();
            
            out.println(username + ":" + password);
            String response = in.readLine();
            System.out.println("Response from server: " + response);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}