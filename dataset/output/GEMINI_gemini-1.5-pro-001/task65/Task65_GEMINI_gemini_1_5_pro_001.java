import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

public class Task65_GEMINI_gemini_1_5_pro_001 {
    public static void main(String[] args) {
        if (args.length < 1) {
            System.out.println("Usage: java Task65_GEMINI_gemini_1_5_pro_001 <filename>");
            System.exit(1);
        }

        String filename = args[0];
        String fileContent = readFile(filename);

        if (fileContent != null) {
            System.out.print(fileContent);
        }
    }

    public static String readFile(String filename) {
        StringBuilder content = new StringBuilder();
        try (BufferedReader reader = new BufferedReader(new FileReader(filename))) {
            String line;
            while ((line = reader.readLine()) != null) {
                content.append(line).append("\n");
            }
        } catch (IOException e) {
            System.err.println("Error reading file '" + filename + "': " + e.getMessage());
            return null;
        }
        return content.toString();
    }
}