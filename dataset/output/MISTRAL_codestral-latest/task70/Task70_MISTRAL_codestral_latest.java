import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

public class Task70_MISTRAL_codestral_latest {
    public static void main(String[] args) {
        if (args.length != 1) {
            System.out.println("Usage: java Task70_MISTRAL_codestral_latest <file_path>");
            return;
        }

        String filePath = args[0];
        StringBuilder content = new StringBuilder();

        try (BufferedReader br = new BufferedReader(new FileReader(filePath))) {
            String line;
            while ((line = br.readLine()) != null) {
                content.append(line).append("\n");
            }
            System.out.println(content.toString());
        } catch (IOException e) {
            System.err.println("Error reading the file: " + e.getMessage());
        }
    }
}