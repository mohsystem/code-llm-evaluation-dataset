
import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.util.Scanner;

public class Task121_CLAUDE_claude_3_5_sonnet_20240620 {
    public static void uploadFile() {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter the filename to upload: ");
        String filename = scanner.nextLine();
        
        File file = new File(filename);
        if (file.exists()) {
            try (FileInputStream fis = new FileInputStream(file)) {
                byte[] content = fis.readAllBytes();
                System.out.println("File \'" + filename + "\' uploaded successfully.");
                System.out.println("File size: " + content.length + " bytes");
            } catch (IOException e) {
                System.out.println("Error reading file: " + e.getMessage());
            }
        } else {
            System.out.println("File \'" + filename + "\' not found.");
        }
        scanner.close();
    }

    public static void main(String[] args) {
        uploadFile();
    }
}
