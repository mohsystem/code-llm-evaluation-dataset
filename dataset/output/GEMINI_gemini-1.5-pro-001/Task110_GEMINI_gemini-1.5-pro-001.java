import java.net.URL;
import java.util.Scanner;

public class ValidateURL {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter a URL to validate: ");
        String urlString = scanner.nextLine();

        try {
            URL url = new URL(urlString);
            System.out.println(urlString + " is a valid URL.");
        } catch (Exception e) {
            System.out.println(urlString + " is not a valid URL.");
        }
    }
}