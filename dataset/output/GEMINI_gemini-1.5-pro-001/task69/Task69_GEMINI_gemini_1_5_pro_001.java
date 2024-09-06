import java.io.File;

public class Task69_GEMINI_gemini_1_5_pro_001 {
    public static void main(String[] args) {
        if (args.length != 1) {
            System.err.println("Usage: java Task69_GEMINI_gemini_1_5_pro_001 <file_path>");
            System.exit(1);
        }

        String filePath = args[0];
        File file = new File(filePath);

        if (!file.exists()) {
            System.err.println("Error: File '" + filePath + "' not found.");
            System.exit(1);
        }

        if (file.delete()) {
            System.out.println("File '" + filePath + "' deleted successfully.");
        } else {
            System.err.println("Error deleting file '" + filePath + "'.");
        }
    }
}