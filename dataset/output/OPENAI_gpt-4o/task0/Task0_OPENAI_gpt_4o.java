import java.io.File;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

public class Task0_OPENAI_gpt_4o {
    
    private static final Lock lock = new ReentrantLock();

    public static void main(String[] args) {
        String directoryPath = "path_to_directory";
        File folder = new File(directoryPath);
        File[] listOfFiles = folder.listFiles();
        ExecutorService executorService = Executors.newFixedThreadPool(10);

        for (File file : listOfFiles) {
            if (file.isFile()) {
                executorService.execute(new FileTask(file));
            }
        }
        executorService.shutdown();
    }

    static class FileTask implements Runnable {
        private final File file;

        FileTask(File file) {
            this.file = file;
        }

        @Override
        public void run() {
            lock.lock();
            try {
                String content = new String(Files.readAllBytes(Paths.get(file.getPath())));
                System.out.println(Thread.currentThread().getName() + " processed: " + content);
            } catch (IOException e) {
                e.printStackTrace();
            } finally {
                lock.unlock();
            }
        }
    }
}