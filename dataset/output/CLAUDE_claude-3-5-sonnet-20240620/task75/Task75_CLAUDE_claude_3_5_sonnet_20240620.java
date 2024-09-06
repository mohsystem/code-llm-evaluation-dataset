
import java.io.IOException;

public class Task75_CLAUDE_claude_3_5_sonnet_20240620 {
    public static void main(String[] args) {
        if (args.length != 1) {
            System.out.println("Usage: java Task75_CLAUDE_claude_3_5_sonnet_20240620 <PID>");
            System.exit(1);
        }

        try {
            int pid = Integer.parseInt(args[0]);
            Process process = Runtime.getRuntime().exec("taskkill /F /PID " + pid);
            int exitCode = process.waitFor();
            
            if (exitCode == 0) {
                System.out.println("Process with PID " + pid + " has been terminated.");
            } else {
                System.out.println("Failed to terminate process with PID " + pid);
            }
        } catch (NumberFormatException e) {
            System.out.println("Invalid PID. Please provide a valid integer.");
        } catch (IOException e) {
            System.out.println("An I/O error occurred: " + e.getMessage());
        } catch (InterruptedException e) {
            System.out.println("The operation was interrupted: " + e.getMessage());
        }
    }
}
