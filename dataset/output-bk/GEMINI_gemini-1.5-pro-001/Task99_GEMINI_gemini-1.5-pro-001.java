import java.io.BufferedReader;
import java.io.FileReader;
import java.util.regex.Pattern;

public class MatchLines {
    public static void main(String[] args) throws Exception {
        BufferedReader reader = new BufferedReader(new FileReader("input.txt"));
        String line;
        Pattern pattern = Pattern.compile("^\\d+.*\\.$");
        while ((line = reader.readLine()) != null) {
            if (pattern.matcher(line).matches()) {
                System.out.println(line);
            }
        }
        reader.close();
    }
}