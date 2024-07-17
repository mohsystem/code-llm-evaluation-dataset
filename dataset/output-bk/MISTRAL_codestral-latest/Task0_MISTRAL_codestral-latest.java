import java.io.File;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.Semaphore;

public class FileProcessor {
    private final Semaphore semaphore = new Semaphore(1);
    private final ExecutorService executor = Executors.newFixedThreadPool(10);

    public void processFiles(File directory) {
        File[] files = directory.listFiles();
        if (files != null) {
            for (File file : files) {
                if (file.isFile()) {
                    executor.submit(() -> {
                        try {
                            semaphore.acquire();
                            // Process the file here
                            semaphore.release();
                        } catch (InterruptedException e) {
                            Thread.currentThread().interrupt();
                        }
                    });
                }
            }
        }
    }
}