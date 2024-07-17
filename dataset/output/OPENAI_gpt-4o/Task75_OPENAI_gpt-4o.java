import java.io.IOException;

public class KillProcess {

    public static void main(String[] args) {
        if (args.length != 1) {
            System.err.println("Usage: java KillProcess <pid>");
            System.exit(1);
        }

        String pid = args[0];
        try {
            Process p = Runtime.getRuntime().exec("kill -9 " + pid);
            p.waitFor();
            if (p.exitValue() == 0) {
                System.out.println("Process " + pid + " terminated.");
            } else {
                System.out.println("Failed to terminate process " + pid + ".");
            }
        } catch (IOException | InterruptedException e) {
            e.printStackTrace();
        }
    }
}