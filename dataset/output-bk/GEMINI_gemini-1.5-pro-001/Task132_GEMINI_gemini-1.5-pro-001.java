import java.io.FileWriter;
import java.io.IOException;
import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;

public class SecurityMonitor {

    public static void main(String[] args) {
        logEvent("System", "Security monitoring started.");
        monitorFilesystem("/path/to/monitor");
    }

    public static void logEvent(String eventType, String description) {
        LocalDateTime now = LocalDateTime.now();
        DateTimeFormatter formatter = DateTimeFormatter.ofPattern("yyyy-MM-dd HH:mm:ss");
        String timestamp = now.format(formatter);
        String logEntry = timestamp + " - [" + eventType + "] - " + description;

        try (FileWriter fileWriter = new FileWriter("security_log.txt", true)) {
            fileWriter.write(logEntry + "
");
        } catch (IOException e) {
            System.err.println("Error writing to log file: " + e.getMessage());
        }

        System.out.println(logEntry);
    }

    public static void monitorFilesystem(String directory) {
        // Placeholder - Implement file monitoring logic here
        while (true) {
            try {
                Thread.sleep(5000);
            } catch (InterruptedException e) {
                System.err.println("Monitoring interrupted: " + e.getMessage());
                // Handle the interruption as needed
            }
            logEvent("File System", "Monitoring directory: " + directory);
        }
    }
}