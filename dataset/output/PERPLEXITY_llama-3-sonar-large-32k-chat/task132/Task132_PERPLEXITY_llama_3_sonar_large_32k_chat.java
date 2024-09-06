import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

public class Task132_PERPLEXITY_llama_3_sonar_large_32k_chat {
    private static final String LOG_FILE = "security_log.txt";

    public static void logEvent(String event) {
        try (PrintWriter out = new PrintWriter(new FileWriter(LOG_FILE, true))) {
            out.println(java.time.LocalDateTime.now() + " - " + event);
        } catch (IOException e) {
            System.err.println("Error writing to log file: " + e.getMessage());
        }
    }

    public static void monitorEvents() {
        Scanner scanner = new Scanner(System.in);
        while (true) {
            System.out.print("Enter an event (or 'quit' to exit): ");
            String event = scanner.nextLine();
            if (event.equalsIgnoreCase("quit")) {
                break;
            }
            logEvent(event);
        }
    }

    public static void main(String[] args) {
        monitorEvents();
    }
}