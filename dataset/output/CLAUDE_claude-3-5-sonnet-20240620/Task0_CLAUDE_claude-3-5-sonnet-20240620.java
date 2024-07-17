
import java.io.*;
import java.nio.file.*;
import java.util.concurrent.*;

class ConcurrentFileProcessor {
    private static final String DIRECTORY_PATH = "shared_directory";
    private static final int NUM_THREADS = 4;

    public static void main(String[] args) {
        ExecutorService executor = Executors.newFixedThreadPool(NUM_THREADS);

        try {
            Files.createDirectories(Paths.get(DIRECTORY_PATH));
            
            while (true) {
                File[] files = new File(DIRECTORY_PATH).listFiles();
                if (files != null) {
                    for (File file : files) {
                        executor.submit(() -> processFile(file));
                    }
                }
                Thread.sleep(1000);
            }
        } catch (IOException | InterruptedException e) {
            e.printStackTrace();
        } finally {
            executor.shutdown();
        }
    }

    private static void processFile(File file) {
        try {
            System.out.println("Processing file: " + file.getName() + " by thread: " + Thread.currentThread().getName());
            // Simulating file processing
            Thread.sleep(2000);
            // Move processed file to a different directory or delete it
            Files.delete(file.toPath());
        } catch (IOException | InterruptedException e) {
            e.printStackTrace();
        }
    }
}
