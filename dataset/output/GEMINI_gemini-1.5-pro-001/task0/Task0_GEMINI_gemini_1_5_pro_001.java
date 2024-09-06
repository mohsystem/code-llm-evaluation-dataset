import java.io.File;
import java.util.concurrent.ConcurrentHashMap;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.TimeUnit;

public class Task0_GEMINI_gemini_1_5_pro_001 {

    private static ConcurrentHashMap<String, Object> fileLocks = new ConcurrentHashMap<>();

    public static void main(String[] args) {
        String directoryPath = "path/to/your/directory"; // Replace with your directory path
        File directory = new File(directoryPath);

        ExecutorService executor = Executors.newFixedThreadPool(Runtime.getRuntime().availableProcessors());

        for (File file : directory.listFiles()) {
            if (file.isFile()) {
                fileLocks.putIfAbsent(file.getAbsolutePath(), new Object());
                executor.execute(() -> processFile(file));
            }
        }

        executor.shutdown();
        try {
            executor.awaitTermination(1, TimeUnit.HOURS);
        } catch (InterruptedException e) {
            System.err.println("Executor termination interrupted: " + e.getMessage());
        }
    }

    private static void processFile(File file) {
        synchronized (fileLocks.get(file.getAbsolutePath())) {
            // Simulate file processing
            System.out.println("Thread " + Thread.currentThread().getName() + " is processing file: " + file.getAbsolutePath());
            // Add your file processing logic here
        }
    }
}