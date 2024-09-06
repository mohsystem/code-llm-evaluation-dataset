import java.lang.Process;

public class Task75_PERPLEXITY_llama_3_sonar_large_32k_chat {
    public static void main(String[] args) {
        if (args.length != 1) {
            System.out.println("Usage: java Task75_PERPLEXITY_llama_3_sonar_large_32k_chat <PID>");
            System.exit(1);
        }

        int pid = Integer.parseInt(args[0]);
        try {
            Runtime.getRuntime().exec("taskkill /pid " + pid);
        } catch (Exception e) {
            System.out.println("Error: " + e);
        }
    }
}