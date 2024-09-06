import java.io.IOException;

public class Task75_GEMINI_gemini_1_5_pro_001 {
    public static void main(String[] args) {
        if (args.length != 1) {
            System.err.println("Usage: java Task75_GEMINI_gemini_1_5_pro_001 <PID>");
            System.exit(1);
        }

        try {
            int pid = Integer.parseInt(args[0]);
            Process process = Runtime.getRuntime().exec(new String[]{"kill", "-9", String.valueOf(pid)});

            // Optionally wait for the process to terminate
            int exitCode = process.waitFor();
            System.out.println("Process with PID " + pid + " terminated with exit code " + exitCode);
        } catch (NumberFormatException e) {
            System.err.println("Error: Invalid PID format.");
            System.exit(1);
        } catch (IOException e) {
            System.err.println("Error terminating process: " + e.getMessage());
            System.exit(1);
        } catch (InterruptedException e) {
            System.err.println("Error: Interrupted while waiting for process termination.");
            System.exit(1);
        }
    }
}