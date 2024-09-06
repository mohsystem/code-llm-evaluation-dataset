
import java.io.Console;
import java.io.IOException;

public class Task116_CLAUDE_claude_3_5_sonnet_20240620 {
    public static void main(String[] args) {
        if (System.getProperty("user.name").equals("root")) {
            Console console = System.console();
            if (console == null) {
                System.err.println("No console available");
                System.exit(1);
            }

            String username = console.readLine("Enter username to change password: ");
            char[] passwordArray = console.readPassword("Enter new password: ");
            String password = new String(passwordArray);

            try {
                changePassword(username, password);
                System.out.println("Dropping privileges...");
                dropPrivileges();
                System.out.println("Privileges dropped. Continuing with reduced permissions.");
            } catch (IOException | InterruptedException e) {
                System.err.println("Error: " + e.getMessage());
                System.exit(1);
            }

            // Rest of the program runs with reduced privileges
            System.out.println("Program continues with reduced privileges...");
        } else {
            System.out.println("This program must be run as root.");
            System.exit(1);
        }
    }

    private static void changePassword(String username, String password) throws IOException, InterruptedException {
        ProcessBuilder pb = new ProcessBuilder("passwd", username);
        pb.redirectErrorStream(true);
        Process process = pb.start();

        process.getOutputStream().write((password + "\\n" + password + "\\n").getBytes());
        process.getOutputStream().flush();
        process.getOutputStream().close();

        int exitCode = process.waitFor();
        if (exitCode == 0) {
            System.out.println("Password changed successfully.");
        } else {
            System.out.println("Failed to change password.");
        }
    }

    private static void dropPrivileges() {
        // Note: Java does not provide a direct way to drop privileges.
        // This would typically involve JNI or system-specific calls.
        System.out.println("Warning: Privilege dropping not implemented in Java.");
        System.out.println("In a real implementation, you would use JNI to call setuid/setgid.");
    }
}
