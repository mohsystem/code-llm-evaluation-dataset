
import java.io.BufferedReader;
import java.io.FileReader;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class Task100_CLAUDE_claude_3_5_sonnet_20240620 {
    public static void main(String[] args) {
        if (args.length != 2) {
            System.out.println("Usage: java Task100_CLAUDE_claude_3_5_sonnet_20240620 <regex_pattern> <file_name>");
            System.exit(1);
        }

        String pattern = args[0];
        String fileName = args[1];

        try {
            Pattern regex = Pattern.compile(pattern);
            BufferedReader reader = new BufferedReader(new FileReader(fileName));
            String line;
            while ((line = reader.readLine()) != null) {
                Matcher matcher = regex.matcher(line);
                if (matcher.find()) {
                    System.out.println(line);
                }
            }
            reader.close();
        } catch (Exception e) {
            System.out.println("Error: " + e.getMessage());
        }
    }
}
