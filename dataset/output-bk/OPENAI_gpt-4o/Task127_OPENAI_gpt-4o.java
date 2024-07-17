import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;

public class FileHandler {
    public static void main(String[] args) {
        String sourcePath = "source.txt";
        String destinationPath = "/tmp/destination.txt";
        
        try (FileInputStream fis = new FileInputStream(new File(sourcePath));
             FileOutputStream fos = new FileOutputStream(new File(destinationPath))) {
            
            byte[] buffer = new byte[1024];
            int length;
            while ((length = fis.read(buffer)) > 0) {
                fos.write(buffer, 0, length);
            }
            System.out.println("File copied successfully in Java!");
        } catch (IOException e) {
            System.out.println("An error occurred while handling the file: " + e.getMessage());
        }
    }
}