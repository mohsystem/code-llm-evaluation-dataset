import java.io.File;
import java.io.FileReader;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

class FileProcessor implements Runnable {
    private String fileName;

    public FileProcessor(String fileName) {
        this.fileName = fileName;
    }

    @Override
    public void run() {
        synchronized (this) {
            System.out.println("Processing file: " + fileName);
            try (FileReader fileReader = new FileReader(fileName)) {
                char[] buffer = new char[1024];
                int bytesRead;
                while ((bytesRead = fileReader.read(buffer)) != -1) {
                    System.out.println("File content: " + new String(buffer, 0, bytesRead));
                }
            } catch (Exception e) {
                e.printStackTrace();
            }
            System.out.println("Finished processing file: " + fileName);
        }
    }
}

public class Task0_PERPLEXITY_llama_3_sonar_large_32k_chat {
    public static void main(String[] args) {
        String directory = "./files";
        File dir = new File(directory);
        File[] files = dir.listFiles();
        ExecutorService executor = Executors.newFixedThreadPool(5);

        for (File file : files) {
            executor.execute(new FileProcessor(file.getAbsolutePath()));
        }

        executor.shutdown();
    }
}