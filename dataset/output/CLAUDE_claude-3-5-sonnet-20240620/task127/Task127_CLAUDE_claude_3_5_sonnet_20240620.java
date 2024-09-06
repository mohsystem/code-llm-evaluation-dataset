
import java.io.*;
import java.nio.file.*;

public class Task127_CLAUDE_claude_3_5_sonnet_20240620 {
    public static void copyFile(String sourcePath, String destPath) {
        try {
            Path source = Paths.get(sourcePath);
            Path destination = Paths.get(destPath);
            Files.copy(source, destination, StandardCopyOption.REPLACE_EXISTING);
            System.out.println("File copied successfully from " + sourcePath + " to " + destPath);
        } catch (NoSuchFileException e) {
            System.out.println("Error: Source file " + sourcePath + " not found.");
        } catch (AccessDeniedException e) {
            System.out.println("Error: Permission denied. Check file permissions.");
        } catch (IOException e) {
            System.out.println("I/O error occurred: " + e.getMessage());
        } catch (Exception e) {
            System.out.println("An unexpected error occurred: " + e.getMessage());
        }
    }

    public static void main(String[] args) {
        String sourceFile = "source.txt";
        String tempDir = "temp";
        String tempFile = tempDir + File.separator + "temp_copy.txt";

        try {
            Files.createDirectories(Paths.get(tempDir));
            copyFile(sourceFile, tempFile);
        } catch (IOException e) {
            System.out.println("Error creating temporary directory: " + e.getMessage());
        } finally {
            try {
                Files.deleteIfExists(Paths.get(tempFile));
                System.out.println("Temporary file " + tempFile + " removed.");
            } catch (IOException e) {
                System.out.println("Error removing temporary file: " + e.getMessage());
            }

            try {
                Files.walk(Paths.get(tempDir))
                    .sorted(java.util.Comparator.reverseOrder())
                    .map(Path::toFile)
                    .forEach(File::delete);
                System.out.println("Temporary directory " + tempDir + " removed.");
            } catch (IOException e) {
                System.out.println("Error removing temporary directory: " + e.getMessage());
            }
        }
    }
}
