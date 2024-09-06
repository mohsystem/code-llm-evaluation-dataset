
import java.io.IOException;
import java.util.Scanner;
import java.util.logging.FileHandler;
import java.util.logging.Logger;
import java.util.logging.SimpleFormatter;

public class Task132_CLAUDE_claude_3_5_sonnet_20240620 {
    private static final Logger LOGGER = Logger.getLogger(Task132_CLAUDE_claude_3_5_sonnet_20240620.class.getName());

    public static void main(String[] args) {
        try {
            FileHandler fileHandler = new FileHandler("security_events.log", true);
            SimpleFormatter formatter = new SimpleFormatter();
            fileHandler.setFormatter(formatter);
            LOGGER.addHandler(fileHandler);
        } catch (IOException e) {
            e.printStackTrace();
            return;
        }

        Scanner scanner = new Scanner(System.in);
        System.out.println("Security Event Monitoring System");

        while (true) {
            System.out.print("Enter event type (or 'q' to quit): ");
            String eventType = scanner.nextLine();
            if (eventType.equalsIgnoreCase("q")) {
                break;
            }

            System.out.print("Enter event description: ");
            String description = scanner.nextLine();

            logEvent(eventType, description);
            System.out.println("Event logged successfully.");
        }

        System.out.println("Monitoring ended. Check 'security_events.log' for recorded events.");
        scanner.close();
    }

    private static void logEvent(String eventType, String description) {
        LOGGER.info("Event Type: " + eventType + ", Description: " + description);
    }
}
