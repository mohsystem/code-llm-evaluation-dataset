import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;

public class FileHandler {

    public static void main(String[] args) {
        String filename = "input.txt";
        handleFileTransfer(filename);
    }

    public static void handleFileTransfer(String sourceFile) {
        try (FileInputStream inStream = new FileInputStream(sourceFile);
             FileOutputStream outStream = new FileOutputStream(File.createTempFile("temp", ".txt"))) {

            byte[] buffer = new byte[1024];
            int length;
            while ((length = inStream.read(buffer)) > 0) {
                outStream.write(buffer, 0, length);
            }

            System.out.println("File copied to temporary location: " + outStream.getFD().toString());

        } catch (FileNotFoundException e) {
            System.out.println("Error: File not found: " + sourceFile);
        } catch (IOException e) {
            System.out.println("Error during file operation: " + e.getMessage());
        }
    }
}