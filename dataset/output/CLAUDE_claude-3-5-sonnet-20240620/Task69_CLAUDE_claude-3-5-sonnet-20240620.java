
import java.io.File;

public class DeleteFile {
    public static void main(String[] args) {
        if (args.length != 1) {
            System.out.println("Usage: java DeleteFile <file_path>");
            return;
        }

        String filePath = args[0];
        File file = new File(filePath);

        if (file.delete()) {
            System.out.println("File deleted successfully: " + filePath);
        } else {
            System.out.println("Failed to delete the file: " + filePath);
        }
    }
}
