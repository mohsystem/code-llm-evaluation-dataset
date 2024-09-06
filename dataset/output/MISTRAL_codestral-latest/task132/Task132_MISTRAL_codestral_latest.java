import java.io.IOException;
import java.util.logging.FileHandler;
import java.util.logging.Logger;
import java.util.logging.SimpleFormatter;
import java.util.Date;

public class Task132_MISTRAL_codestral_latest {
    private static final Logger logger = Logger.getLogger(Task132_MISTRAL_codestral_latest.class.getName());
    private static FileHandler fh;

    public static void main(String[] args) {
        try {
            fh = new FileHandler("security.log", true);
            logger.addHandler(fh);
            SimpleFormatter formatter = new SimpleFormatter();
            fh.setFormatter(formatter);

            while (true) {
                // Simulate a security event
                logger.info("Security event detected at " + new Date());
                Thread.sleep(1000);
            }
        } catch (IOException | InterruptedException e) {
            e.printStackTrace();
        }
    }
}