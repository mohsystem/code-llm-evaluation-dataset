import java.io.IOException;
import java.util.logging.FileHandler;
import java.util.logging.Logger;
import java.util.logging.SimpleFormatter;
import java.util.Date;

public class SecurityMonitor {
    private static final Logger logger = Logger.getLogger(SecurityMonitor.class.getName());
    private static FileHandler fh;

    public static void main(String[] args) {
        try {
            fh = new FileHandler("security.log", true);
            logger.addHandler(fh);
            SimpleFormatter formatter = new SimpleFormatter();
            fh.setFormatter(formatter);

            while (true) {
                String event = "Security event detected at " + new Date();
                logger.info(event);
                Thread.sleep(5000);
            }
        } catch (SecurityException | IOException | InterruptedException e) {
            e.printStackTrace();
        }
    }
}