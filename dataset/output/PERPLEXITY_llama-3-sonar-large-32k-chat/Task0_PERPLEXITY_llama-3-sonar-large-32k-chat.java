import java.io.File;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.locks.ReentrantLock;

class FileProcessor implements Runnable {
    private File file;
    private ReentrantLock lock;

    public FileProcessor(File file, ReentrantLock lock) {
        this.file = file;
        this.lock = lock;
    }

    @Override
    public void run() {
        lock.lock();
        try {
            // Process the file
            System.out.println("Processing file: " + file.getName());
            // Simulate file processing
            Thread.sleep(1000);
        } catch (InterruptedException e) {
            e.printStackTrace();
        } finally {
            lock.unlock();
        }
    }
}

public class ConcurrentFileProcessor {
    public static void main(String[] args) {
        File directory = new File("files");
        File[] files = directory.listFiles();
        ReentrantLock lock = new ReentrantLock();
        ExecutorService executor = Executors.newFixedThreadPool(5);

        for (File file : files) {
            executor.submit(new FileProcessor(file, lock));
        }

        executor.shutdown();
    }
}