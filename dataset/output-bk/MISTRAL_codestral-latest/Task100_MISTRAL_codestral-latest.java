import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class RegexSearch {
    public static void main(String[] args) {
        if (args.length != 2) {
            System.out.println("Usage: java RegexSearch <pattern> <filename>");
            System.exit(1);
        }

        String pattern = args[0];
        String filename = args[1];

        try (BufferedReader br = new BufferedReader(new FileReader(filename))) {
            Pattern regexPattern = Pattern.compile(pattern);
            String line;
            while ((line = br.readLine()) != null) {
                Matcher matcher = regexPattern.matcher(line);
                while (matcher.find()) {
                    System.out.println("Match found: " + matcher.group());
                }
            }
        } catch (IOException e) {
            System.err.println("Error reading file: " + e.getMessage());
        }
    }
}