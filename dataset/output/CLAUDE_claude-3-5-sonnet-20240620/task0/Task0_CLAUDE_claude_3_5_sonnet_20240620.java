
import java.io.File;
import java.util.HashSet;
import java.util.Set;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

public class Task0_CLAUDE_claude_3_5_sonnet_20240620 {
    private final String directory;
    private final Set<String> processedFiles;

    public Task0_CLAUDE_claude_3_5_sonnet_20240620(String directory) {
        this.directory = directory;
        this.processedFiles = new HashSet<>();
    }

    public void processFile(String filename) {
        synchronized (processedFiles) {
            if (processedFiles.contains(filename)) {
                return;
            }
            processedFiles.add(filename);
        }

        System.out.println("Processing file: " + filename);
        try {
            Thread.sleep(1000); // Simulate file processing
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        System.out.println("Finished processing file: " + filename);
    }

    public void processDirectory() {
        File dir = new File(directory);
        File[] files = dir.listFiles((d, name) -> name.endsWith(".txt"));

        ExecutorService executor = Executors.newFixedThreadPool(4);

        if (files != null) {
            for (File file : files) {
                executor.submit(() -> processFile(file.getName()));
            }
        }

        executor.shutdown();
    }

    public static void main(String[] args) {
        Task0_CLAUDE_claude_3_5_sonnet_20240620 processor = new Task0_CLAUDE_claude_3_5_sonnet_20240620("./files");
        processor.processDirectory();
    }
}
