import java.util.regex.*;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;

public class MultiLangMain {
    public static void main(String[] args) {
        if (args.length < 2) {
            System.out.println("Usage: java MultiLangMain <pattern> <filename>");
            return;
        }
        String patternString = args[0];
        String filename = args[1];

        try {
            String content = new String(Files.readAllBytes(Paths.get(filename)));
            Pattern pattern = Pattern.compile(patternString);
            Matcher matcher = pattern.matcher(content);

            while (matcher.find()) {
                System.out.println(matcher.group());
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}