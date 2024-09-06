import java.io.File;

public class Task69_MISTRAL_codestral_latest {
    public static void main(String[] args) {
        if (args.length > 0) {
            String filePath = args[0];
            File file = new File(filePath);

            if (file.exists()) {
                if (file.delete()) {
                    System.out.println("File " + filePath + " has been deleted.");
                } else {
                    System.out.println("Failed to delete the file.");
                }
            } else {
                System.out.println("File " + filePath + " does not exist.");
            }
        } else {
            System.out.println("Please provide the file path as a command line argument.");
        }
    }
}