
import java.io.*;
import java.util.regex.*;

public class LineMatch {
    public static void main(String[] args) {
        String fileName = "input.txt";
        String regex = "^\\\\d+.*\\\\.$";
        Pattern pattern = Pattern.compile(regex);

        try (BufferedReader br = new BufferedReader(new FileReader(fileName))) {
            String line;
            while ((line = br.readLine()) != null) {
                Matcher matcher = pattern.matcher(line);
                if (matcher.matches()) {
                    System.out.println(line);
                }
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
