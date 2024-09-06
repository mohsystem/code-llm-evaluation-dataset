// Java does not have built-in support for changing user passwords or dropping privileges.
// This is a simplified example of how you might use ProcessBuilder to run a shell command.

import java.io.IOException;
import java.util.Scanner;

public class Task116_MISTRAL_codestral_latest {
    public static void main(String[] args) throws IOException, InterruptedException {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter username: ");
        String username = scanner.nextLine();
        System.out.print("Enter new password: ");
        String newPassword = scanner.nextLine();

        ProcessBuilder pb = new ProcessBuilder("sudo", "chpasswd");
        Process p = pb.start();
        p.getOutputStream().write((username + ":" + newPassword).getBytes());
        p.getOutputStream().flush();
        p.getOutputStream().close();
        p.waitFor();

        // Dropping privileges is not directly supported in Java.
        // You would need to use a native library or JNA (Java Native Access) for this.
    }
}