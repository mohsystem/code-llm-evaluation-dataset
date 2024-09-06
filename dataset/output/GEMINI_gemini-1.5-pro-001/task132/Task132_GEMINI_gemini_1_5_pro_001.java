import java.io.File;
import java.io.IOException;
import java.nio.file.*;
import java.util.logging.FileHandler;
import java.util.logging.Logger;
import java.util.logging.SimpleFormatter;

public class Task132_GEMINI_gemini_1_5_pro_001 {

    private static final Logger LOGGER = Logger.getLogger(Task132_GEMINI_gemini_1_5_pro_001.class.getName());

    public static void main(String[] args) throws IOException {
        // Configure logger to write to a file
        FileHandler fh = new FileHandler("security_events.log", true);
        LOGGER.addHandler(fh);
        SimpleFormatter formatter = new SimpleFormatter();
        fh.setFormatter(formatter);

        String fileToMonitor = "/path/to/your/important_file.txt"; // Replace with the actual file path
        watchFileChanges(fileToMonitor);
    }

    private static void watchFileChanges(String filePath) throws IOException {
        Path path = Paths.get(filePath);
        WatchService watchService = FileSystems.getDefault().newWatchService();
        path.getParent().register(watchService, StandardWatchEventKinds.ENTRY_MODIFY);

        while (true) {
            try {
                WatchKey key = watchService.take();
                for (WatchEvent<?> event : key.pollEvents()) {
                    if (event.kind() == StandardWatchEventKinds.ENTRY_MODIFY) {
                        LOGGER.info("File Change Detected: File '" + filePath + "' has been modified.");
                    }
                }
                key.reset();
            } catch (InterruptedException e) {
                LOGGER.severe("Error while monitoring file changes: " + e.getMessage());
                Thread.currentThread().interrupt();
            }
        }
    }
}