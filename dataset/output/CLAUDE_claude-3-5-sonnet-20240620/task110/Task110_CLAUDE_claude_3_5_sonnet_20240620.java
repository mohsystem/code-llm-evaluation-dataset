
import java.util.Scanner;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class Task110_CLAUDE_claude_3_5_sonnet_20240620 {
    public static boolean isValidURL(String url) {
        String regex = "^(https?|ftp)://[^\\\\s/$.?#].[^\\\\s]*$";
        Pattern pattern = Pattern.compile(regex, Pattern.CASE_INSENSITIVE);
        Matcher matcher = pattern.matcher(url);
        return matcher.matches();
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        while (true) {
            System.out.print("Enter a URL (or 'quit' to exit): ");
            String url = scanner.nextLine();
            if (url.equalsIgnoreCase("quit")) {
                break;
            }
            if (isValidURL(url)) {
                System.out.println("Valid URL");
            } else {
                System.out.println("Invalid URL");
            }
        }
        scanner.close();
    }
}
