import java.io.FileWriter;
import java.io.IOException;
import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;

public class SecurityLogger {

    private static final String LOG_FILE_PATH = "security.log";
    private static DateTimeFormatter dtf = DateTimeFormatter.ofPattern("yyyy/MM/dd HH:mm:ss");

    public static void logEvent(String event) {
        try (FileWriter fw = new FileWriter(LOG_FILE_PATH, true)) {
            fw.write(LocalDateTime.now().format(dtf) + " - " + event + "
");
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public static void main(String[] args) {
        logEvent("User login detected.");
        logEvent("Unauthorized access attempt detected.");
        logEvent("File integrity check failed.");
    }
}