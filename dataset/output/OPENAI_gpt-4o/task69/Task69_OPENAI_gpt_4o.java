import java.io.File;

public class Task69_OPENAI_gpt_4o {
    public static void main(String[] args) {
        if (args.length != 1) {
            System.out.println("Usage: java Task69_OPENAI_gpt_4o <file_path>");
            System.exit(1);
        }

        String filePath = args[0];
        File file = new File(filePath);

        if (file.delete()) {
            System.out.println(filePath + " deleted successfully.");
        } else {
            System.out.println("Error deleting " + filePath + ".");
        }
    }
}