// Java
import java.io.File;

public class DeleteFile {
    public static void main(String[] args) {
        if (args.length > 0) {
            File file = new File(args[0]);
            if (file.exists()) {
                if (file.delete()) {
                    System.out.println("File deleted successfully");
                } else {
                    System.out.println("Failed to delete the file");
                }
            } else {
                System.out.println("File does not exist");
            }
        } else {
            System.out.println("Please provide a file path as an argument");
        }
    }
}