// Java client
import java.io.*;
import java.net.*;
import java.util.Scanner;

public class Task7_MISTRAL_codestral_latest {
    public static void main(String[] args) throws IOException {
        Socket socket = new Socket("localhost", 12345);
        PrintWriter out = new PrintWriter(socket.getOutputStream(), true);
        BufferedReader in = new BufferedReader(new InputStreamReader(socket.getInputStream()));

        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter your username: ");
        String username = scanner.nextLine();
        System.out.print("Enter your password: ");
        String password = scanner.nextLine();

        out.println("LOGIN|" + username + "|" + password);
        String response = in.readLine();
        System.out.println(response);

        socket.close();
    }
}