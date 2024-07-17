
import java.io.Console;
import java.io.IOException;

public class PrivilegeDropper {
    public static void main(String[] args) {
        Console console = System.console();
        if (console == null) {
            System.err.println("No console available");
            System.exit(1);
        }

        String username = console.readLine("Enter username to change password: ");
        char[] password = console.readPassword("Enter new password: ");

        // Perform privileged operation
        try {
            Runtime.getRuntime().exec("sudo passwd " + username);
            System.out.println("Password changed successfully");
        } catch (IOException e) {
            System.err.println("Failed to change password: " + e.getMessage());
            System.exit(1);
        }

        // Drop privileges
        try {
            Runtime.getRuntime().exec("sudo -k");
            System.out.println("Privileges dropped");
        } catch (IOException e) {
            System.err.println("Failed to drop privileges: " + e.getMessage());
            System.exit(1);
        }
    }
}
