import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;

public class ReadFileContent {
    public static void main(String[] args) throws IOException {
        if (args.length == 0) {
            System.err.println("Please provide the file path as a command line argument.");
            System.exit(1);
        }
        String filePath = args[0];
        String content = new String(Files.readAllBytes(Paths.get(filePath)));
        System.out.print(content);
    }
}