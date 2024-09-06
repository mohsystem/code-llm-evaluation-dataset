import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class Task100_MISTRAL_codestral_latest {
    public static void main(String[] args) {
        String pattern = args[0];
        String fileName = args[1];

        try {
            File file = new File(fileName);
            Scanner scanner = new Scanner(file);
            Pattern regexPattern = Pattern.compile(pattern);

            while (scanner.hasNextLine()) {
                String line = scanner.nextLine();
                Matcher matcher = regexPattern.matcher(line);

                while (matcher.find()) {
                    System.out.println(matcher.group());
                }
            }

            scanner.close();
        } catch (FileNotFoundException e) {
            System.out.println("File not found: " + fileName);
        }
    }
}