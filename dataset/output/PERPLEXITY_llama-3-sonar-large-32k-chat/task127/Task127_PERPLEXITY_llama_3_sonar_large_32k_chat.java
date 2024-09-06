import java.io.File;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;

public class Task127_PERPLEXITY_llama_3_sonar_large_32k_chat {
    public static void main(String[] args) {
        String srcDir = "/path/to/source/directory";
        String dstDir = "/path/to/temporary/directory";
        String filename = "file.txt";

        try {
            Path srcFile = Paths.get(srcDir, filename);
            Path dstFile = Paths.get(dstDir, filename);

            Files.copy(srcFile, dstFile);

            System.out.println("File " + filename + " has been copied to " + dstDir);
        } catch (IOException e) {
            if (e instanceof FileNotFoundException) {
                System.out.println("Error: File " + filename + " not found in " + srcDir);
            } else if (e instanceof SecurityException) {
                System.out.println("Error: Permission denied to read from " + srcDir + " or write to " + dstDir);
            } else {
                System.out.println("An error occurred: " + e.getMessage());
            }
        }
    }
}