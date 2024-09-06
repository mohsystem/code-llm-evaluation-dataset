import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;

public class Task70_OPENAI_gpt_4o {
    public static void main(String[] args) {
        if (args.length != 1) {
            System.out.println("Usage: java Task70_OPENAI_gpt_4o <file_path>");
            return;
        }

        String filePath = args[0];

        try {
            String content = new String(Files.readAllBytes(Paths.get(filePath)));
            System.out.println(content);
        } catch (IOException e) {
            System.out.println("An error occurred: " + e.getMessage());
        }
    }
}