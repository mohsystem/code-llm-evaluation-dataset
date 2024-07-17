
import java.util.regex.Matcher;
import java.util.regex.Pattern;
import java.util.Scanner;

public class URLValidator {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter a URL: ");
        String url = scanner.nextLine();
        scanner.close();

        String regex = "^(https?://)?([\\\\da-z.-]+)\\\\.([a-z.]{2,6})(:[0-9]+)?([/\\\\w .-]*)*/?$";
        Pattern pattern = Pattern.compile(regex);
        Matcher matcher = pattern.matcher(url);

        if (matcher.matches()) {
            System.out.println("Valid URL");
        } else {
            System.out.println("Invalid URL");
        }
    }
}
