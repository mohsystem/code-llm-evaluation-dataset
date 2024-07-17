
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class RegexFileSearch {
    public static void main(String[] args) {
        if (args.length != 2) {
            System.out.println("Usage: java RegexFileSearch <regex_pattern> <file_name>");
            System.exit(1);
        }

        String regexPattern = args[0];
        String fileName = args[1];

        try {
            Pattern pattern = Pattern.compile(regexPattern);
            BufferedReader reader = new BufferedReader(new FileReader(fileName));
            String line;
            int lineNumber = 0;

            while ((line = reader.readLine()) != null) {
                lineNumber++;
                Matcher matcher = pattern.matcher(line);
                while (matcher.find()) {
                    System.out.printf("Line %d: %s%n", lineNumber, matcher.group());
                }
            }

            reader.close();
        } catch (IOException e) {
            System.out.println("Error reading file: " + e.getMessage());
        } catch (Exception e) {
            System.out.println("Error: " + e.getMessage());
        }
    }
}
