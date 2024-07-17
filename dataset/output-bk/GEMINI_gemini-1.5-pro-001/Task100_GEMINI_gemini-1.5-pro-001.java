import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class RegexFileSearch {
    public static void main(String[] args) throws IOException {
        if (args.length != 2) {
            System.err.println("Usage: java RegexFileSearch <regex> <filename>");
            System.exit(1);
        }

        String regex = args[0];
        String filename = args[1];

        String content = new String(Files.readAllBytes(Paths.get(filename)));

        Pattern pattern = Pattern.compile(regex);
        Matcher matcher = pattern.matcher(content);

        while (matcher.find()) {
            System.out.println(matcher.group());
        }
    }
}