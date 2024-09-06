import java.io.BufferedReader;
import java.io.FileReader;
import java.util.regex.Pattern;

public class Task99_GEMINI_gemini_1_5_pro_001 {
    public static void main(String[] args) throws Exception {
        BufferedReader reader = new BufferedReader(new FileReader("input.txt"));
        String line;
        while ((line = reader.readLine()) != null) {
            if (Pattern.matches("^\\d+\\.$", line)) {
                System.out.println(line);
            }
        }
        reader.close();
    }
}