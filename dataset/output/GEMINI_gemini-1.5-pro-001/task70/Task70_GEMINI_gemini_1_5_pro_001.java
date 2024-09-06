import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;

public class Task70_GEMINI_gemini_1_5_pro_001 {
  public static void main(String[] args) {
    if (args.length < 1) {
      System.err.println("Error: Please provide the file path as a command-line argument.");
      System.exit(1);
    }

    String filePath = args[0];
    try {
      String fileContent = new String(Files.readAllBytes(Paths.get(filePath)));
      System.out.println(fileContent);
    } catch (IOException e) {
      System.err.println("Error reading file: " + e.getMessage());
      System.exit(1);
    }
  }
}