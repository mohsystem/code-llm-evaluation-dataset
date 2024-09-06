import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class Task100_GEMINI_gemini_1_5_pro_001 {
    public static void main(String[] args) {
        if (args.length < 2) {
            System.err.println("Usage: java Task100_GEMINI_gemini_1_5_pro_001 <regex_pattern> <file_name>");
            System.exit(1);
        }

        String pattern = args[0];
        String fileName = args[1];

        try (BufferedReader reader = new BufferedReader(new FileReader(fileName))) {
            String line;
            while ((line = reader.readLine()) != null) {
                Pattern regex = Pattern.compile(pattern);
                Matcher matcher = regex.matcher(line);
                if (matcher.find()) {
                    System.out.println(line);
                }
            }
        } catch (IOException e) {
            System.err.println("Error reading file: " + e.getMessage());
            System.exit(1);
        }
    }
}