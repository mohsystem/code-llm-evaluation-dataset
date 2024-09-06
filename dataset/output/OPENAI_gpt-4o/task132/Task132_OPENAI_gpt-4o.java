import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;
import java.util.ArrayList;

class SecurityEventLogger {
    private ArrayList<String> events = new ArrayList<>();

    public void logEvent(String event) {
        String timestamp = LocalDateTime.now().format(DateTimeFormatter.ofPattern("yyyy-MM-dd HH:mm:ss"));
        events.add(timestamp + " - " + event);
    }

    public void showEvents() {
        for (String event : events) {
            System.out.println(event);
        }
    }

    public static void main(String[] args) {
        SecurityEventLogger logger = new SecurityEventLogger();
        logger.logEvent("User login");
        logger.logEvent("File accessed");
        try {
            Thread.sleep(1000); // Sleep for 1 second
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        logger.logEvent("User logout");
        logger.showEvents();
    }
}