
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.regex.Pattern;

public class Task99_CLAUDE_claude_3_5_sonnet_20240620 {
    public static void main(String[] args) {
        String pattern = "^\\\\d+.*\\\\.$";
        
        try (BufferedReader br = new BufferedReader(new FileReader("input.txt"))) {
            String line;
            while ((line = br.readLine()) != null) {
                if (Pattern.matches(pattern, line.trim())) {
                    System.out.println(line.trim());
                }
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
