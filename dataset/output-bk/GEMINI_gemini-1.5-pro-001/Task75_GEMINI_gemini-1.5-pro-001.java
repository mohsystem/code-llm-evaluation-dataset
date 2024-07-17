public class terminate_process {
    public static void main(String[] args) {
        if (args.length != 1) {
            System.err.println("Usage: java terminate_process <PID>");
            System.exit(1);
        }
        try {
            int pid = Integer.parseInt(args[0]);
            Process process = Runtime.getRuntime().exec(new String[]{"kill", String.valueOf(pid)});
            int exitCode = process.waitFor();
            if (exitCode == 0) {
                System.out.println("Process with PID " + pid + " terminated successfully.");
            } else {
                System.err.println("Error terminating process with PID " + pid + ". Exit code: " + exitCode);
            }
        } catch (NumberFormatException e) {
            System.err.println("Invalid PID provided. Please provide an integer.");
            System.exit(1);
        } catch (Exception e) {
            System.err.println("Error terminating process: " + e.getMessage());
            System.exit(1);
        }
    }
}