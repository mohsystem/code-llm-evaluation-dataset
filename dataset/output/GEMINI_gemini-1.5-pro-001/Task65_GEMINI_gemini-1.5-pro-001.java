import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;

public class FileDataGetter {

    public static void main(String[] args) {
        if (args.length == 0) {
            System.err.println("Error: Filename is required as a command-line argument.");
            return;
        }

        String filename = args[0];
        String fileContent = readFromFile(filename);

        if (fileContent != null) {
            System.out.println(fileContent);
        }
    }

    public static String readFromFile(String filename) {
        File file = new File(filename);
        if (!file.exists()) {
            System.err.println("Error: File '" + filename + "' does not exist.");
            return null;
        }

        if (!file.isFile()) {
            System.err.println("Error: '" + filename + "' is not a valid file.");
            return null;
        }

        StringBuilder content = new StringBuilder();
        try (BufferedReader reader = new BufferedReader(new FileReader(file))) {
            String line;
            while ((line = reader.readLine()) != null) {
                content.append(line).append(System.lineSeparator());
            }
        } catch (IOException e) {
            System.err.println("Error reading file: " + e.getMessage());
            return null;
        }

        return content.toString();
    }
}