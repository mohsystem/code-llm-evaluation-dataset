
import java.io.IOException;

public class ProcessTerminator {
    public static void main(String[] args) {
        if (args.length != 1) {
            System.out.println("Usage: java ProcessTerminator <PID>");
            System.exit(1);
        }

        int pid;
        try {
            pid = Integer.parseInt(args[0]);
        } catch (NumberFormatException e) {
            System.out.println("Invalid PID. Please provide a valid integer.");
            System.exit(1);
            return;
        }

        try {
            Process process = Runtime.getRuntime().exec("taskkill /F /PID " + pid);
            int exitCode = process.waitFor();
            if (exitCode == 0) {
                System.out.println("Process with PID " + pid + " terminated successfully.");
            } else {
                System.out.println("Failed to terminate process with PID " + pid);
            }
        } catch (IOException | InterruptedException e) {
            System.out.println("Error occurred while terminating the process: " + e.getMessage());
        }
    }
}
