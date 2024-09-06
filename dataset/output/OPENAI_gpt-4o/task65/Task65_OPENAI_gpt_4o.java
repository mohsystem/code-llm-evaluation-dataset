import java.nio.file.*;
import java.io.IOException;
import java.nio.charset.StandardCharsets;

public class Task65_OPENAI_gpt_4o {
    public static void main(String[] args) {
        if (args.length != 1) {
            System.out.println("Usage: java Task65_OPENAI_gpt_4o <filename>");
            return;
        }
        
        String filename = args[0];
        Path path = Paths.get(filename);
        
        if (!Files.exists(path)) {
            System.out.println("File does not exist");
        } else {
            try {
                String content = Files.readString(path, StandardCharsets.UTF_8);
                System.out.println(content);
            } catch (IOException e) {
                System.out.println("Error reading file: " + e.getMessage());
            }
        }
    }
}