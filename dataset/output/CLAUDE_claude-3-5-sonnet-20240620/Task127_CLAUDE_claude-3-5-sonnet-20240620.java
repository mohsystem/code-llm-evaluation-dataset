
import java.io.*;
import java.nio.file.*;

public class FileCopyWithExceptions {
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
        String sourcePath = "path/to/source/file.txt";
        String destPath = "/tmp/copied_file.txt";
        copyFile(sourcePath, destPath);
    }
}
