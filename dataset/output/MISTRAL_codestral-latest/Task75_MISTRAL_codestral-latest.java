// Java
import java.lang.management.ManagementFactory;
import java.lang.management.RuntimeMXBean;
import java.lang.management.StringOperationException;

public class TerminateProcess {
    public static void main(String[] args) {
        if (args.length != 1) {
            System.out.println("Usage: java TerminateProcess <PID>");
            return;
        }

        int pid = Integer.parseInt(args[0]);
        String name = ManagementFactory.getRuntimeMXBean().getName();
        int currentPid = Integer.parseInt(name.split("@")[0]);

        if (pid == currentPid) {
            System.out.println("Cannot terminate the current process.");
            return;
        }

        try {
            Runtime.getRuntime().exec("kill " + pid);
            System.out.println("Process " + pid + " terminated.");
        } catch (Exception e) {
            System.out.println("Error terminating process: " + e.getMessage());
        }
    }
}