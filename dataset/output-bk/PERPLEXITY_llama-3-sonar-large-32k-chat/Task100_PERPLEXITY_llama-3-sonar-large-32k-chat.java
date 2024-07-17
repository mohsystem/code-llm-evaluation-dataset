import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.regex.Pattern;
import java.util.regex.Matcher;

public class RegexSearch {
    public static void main(String[] args) {
        if (args.length != 2) {
            System.out.println("Usage: java RegexSearch <pattern> <file>");
            return;
        }
        String pattern = args[0];
        String file = args[1];
        try (BufferedReader br = new BufferedReader(new FileReader(file))) {
            String line;
            Pattern p = Pattern.compile(pattern);
            while ((line = br.readLine()) != null) {
                Matcher m = p.matcher(line);
                while (m.find()) {
                    System.out.println(m.group());
                }
            }
        } catch (IOException e) {
            System.out.println("Error reading file: " + e.getMessage());
        }
    }
}