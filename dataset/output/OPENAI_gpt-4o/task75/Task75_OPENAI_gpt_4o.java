import java.util.Scanner;

public class Task75_OPENAI_gpt_4o {
    public static void main(String[] args) {
        if (args.length != 1) {
            System.out.println("Usage: java Task75_OPENAI_gpt_4o <PID>");
            return;
        }
        int pid = Integer.parseInt(args[0]);
        try {
            String cmd = "kill -9 " + pid;
            Runtime.getRuntime().exec(cmd);
            System.out.println("Process " + pid + " terminated.");
        } catch (Exception e) {
            System.out.println("Error: " + e.getMessage());
        }
    }
}