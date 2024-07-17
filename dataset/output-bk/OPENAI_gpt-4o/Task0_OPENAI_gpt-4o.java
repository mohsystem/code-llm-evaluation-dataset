import java.io.*;
import java.nio.file.*;
import java.util.concurrent.*;

class FileProcessor implements Runnable {
    private static final ConcurrentHashMap<String, Object> locks = new ConcurrentHashMap<>();
    private String fileName;

    public FileProcessor(String fileName) {
        this.fileName = fileName;
    }

    @Override
    public void run() {
        Object fileLock = locks.computeIfAbsent(fileName, k -> new Object());
        synchronized (fileLock) {
            processFile(fileName);
            locks.remove(fileName); // Cleanup the lock
        }
    }

    private void processFile(String fileName) {
        // Simulate file processing
        System.out.println("Processing " + fileName + " by " + Thread.currentThread().getName());
        try {
            Thread.sleep(1000); // Simulate time-consuming task
        } catch (InterruptedException e) {
            Thread.currentThread().interrupt();
        }
    }

    public static void main(String[] args) throws IOException {
        ExecutorService executor = Executors.newFixedThreadPool(10);
        Files.list(Paths.get("shared_directory"))
                .filter(Files::isRegularFile)
                .forEach(filePath -> executor.submit(new FileProcessor(filePath.toString())));

        executor.shutdown();
    }
}