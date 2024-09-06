
import java.io.File;

public class Task69_CLAUDE_claude_3_5_sonnet_20240620 {
    public static void main(String[] args) {
        if (args.length != 1) {
            System.out.println("Usage: java Task69_CLAUDE_claude_3_5_sonnet_20240620 <file_path>");
            System.exit(1);
        }

        String filePath = args[0];
        File file = new File(filePath);

        if (file.delete()) {
            System.out.println("File '" + filePath + "' has been deleted successfully.");
        } else {
            if (!file.exists()) {
                System.out.println("File '" + filePath + "' not found.");
            } else {
                System.out.println("Unable to delete '" + filePath + "'. It may be a directory or you may not have permission.");
            }
        }
    }
}
