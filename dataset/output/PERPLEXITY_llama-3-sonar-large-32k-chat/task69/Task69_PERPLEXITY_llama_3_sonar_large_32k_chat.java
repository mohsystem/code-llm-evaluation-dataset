import java.io.File;
import java.io.IOException;

public class Task69_PERPLEXITY_llama_3_sonar_large_32k_chat {
    public static void main(String[] args) {
        if (args.length != 1) {
            System.out.println("Usage: java Task69_PERPLEXITY_llama_3_sonar_large_32k_chat <file_path>");
            System.exit(1);
        }

        String filePath = args[0];

        File file = new File(filePath);

        if (file.delete()) {
            System.out.println("File deleted successfully");
        } else {
            System.out.println("Failed to delete the file");
        }
    }
}