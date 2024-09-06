
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;

public class Task65_CLAUDE_claude_3_5_sonnet_20240620 {
    public static void readFile(String filename) {
        if (!filename.endsWith(".txt")) {
            System.out.println("Error: File must have a .txt extension");
            return;
        }

        if (!Files.exists(Paths.get(filename))) {
            System.out.println("Error: File '" + filename + "' does not exist");
            return;
        }

        try (BufferedReader reader = new BufferedReader(new Task65_CLAUDE_claude_3_5_sonnet_20240620(filename))) {
            String line;
            System.out.println("File contents:");
            while ((line = reader.readLine()) != null) {
                System.out.println(line);
            }
        } catch (IOException e) {
            System.out.println("Error: Unable to read file '" + filename + "'");
        }
    }

    public static void main(String[] args) {
        if (args.length != 1) {
            System.out.println("Usage: java Task65_CLAUDE_claude_3_5_sonnet_20240620 <filename>");
        } else {
            readFile(args[0]);
        }
    }
}
