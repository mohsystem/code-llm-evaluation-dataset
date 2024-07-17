import java.io.File;
import java.io.IOException;

public class DeleteFile {
    public static void main(String[] args) {
        if (args.length != 1) {
            System.out.println("Usage: java DeleteFile <file_path>");
            return;
        }
        File file = new File(args[0]);
        if (file.delete()) {
            System.out.println("File deleted successfully");
        } else {
            System.out.println("Failed to delete the file");
        }
    }
}