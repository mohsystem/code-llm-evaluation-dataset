import java.io.File;

public class DeleteFile {
    public static void main(String[] args) {
        if (args.length == 0) {
            System.err.println("Error: File path not provided.");
            return;
        }

        String filePath = args[0];

        File file = new File(filePath);

        if (file.delete()) {
            System.out.println("File deleted successfully.");
        } else {
            System.err.println("Failed to delete the file. File may not exist.");
        }
    }
}