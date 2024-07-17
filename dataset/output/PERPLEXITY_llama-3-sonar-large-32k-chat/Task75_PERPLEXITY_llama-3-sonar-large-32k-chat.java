import java.lang.Process;

public class Main {
    public static void main(String[] args) {
        if (args.length != 1) {
            System.out.println("Usage: java Main <PID>");
            return;
        }
        try {
            Process process = Runtime.getRuntime().exec("taskkill /pid " + args[0]);
            process.waitFor();
        } catch (Exception e) {
            System.out.println("Error: " + e.getMessage());
        }
    }
}