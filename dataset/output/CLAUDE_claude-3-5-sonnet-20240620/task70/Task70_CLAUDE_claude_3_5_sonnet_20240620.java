
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

public class Task70_CLAUDE_claude_3_5_sonnet_20240620 {
    public static void main(String[] args) {
        if (args.length != 1) {
            System.out.println("Usage: java Task70_CLAUDE_claude_3_5_sonnet_20240620 <file_path>");
            return;
        }

        String filePath = args[0];
        
        try (BufferedReader reader = new BufferedReader(new Task70_CLAUDE_claude_3_5_sonnet_20240620(filePath))) {
            String line;
            while ((line = reader.readLine()) != null) {
                System.out.println(line);
            }
        } catch (IOException e) {
            System.out.println("Error reading file: " + e.getMessage());
        }
    }
}
