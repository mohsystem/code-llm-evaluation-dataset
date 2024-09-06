import java.util.regex.*;
import java.util.Scanner;

public class Task110_OPENAI_gpt_4o {
    public static boolean validateURL(String url) {
        String regex = "^(https?|ftp)://[^\\s/$.?#].[^\\s]*$";
        Pattern pattern = Pattern.compile(regex, Pattern.CASE_INSENSITIVE);
        Matcher matcher = pattern.matcher(url);
        return matcher.matches();
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter URL: ");
        String userURL = scanner.nextLine();

        if (validateURL(userURL)) {
            System.out.println("Valid URL");
        } else {
            System.out.println("Invalid URL");
        }

        scanner.close();
    }
}