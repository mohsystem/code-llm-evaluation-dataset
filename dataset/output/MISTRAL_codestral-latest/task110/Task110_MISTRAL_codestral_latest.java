import java.util.regex.Matcher;
import java.util.regex.Pattern;
import java.util.Scanner;

public class Task110_MISTRAL_codestral_latest {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter a URL: ");
        String url = scanner.nextLine();
        if (validateURL(url)) {
            System.out.println("Valid URL");
        } else {
            System.out.println("Invalid URL");
        }
    }

    public static boolean validateURL(String url) {
        String regex = "^(https?|ftp|file)://[-a-zA-Z0-9+&@#/%?=~_|!:,.;]*[-a-zA-Z0-9+&@#/%=~_|]";
        Pattern pattern = Pattern.compile(regex);
        Matcher matcher = pattern.matcher(url);
        return matcher.matches();
    }
}