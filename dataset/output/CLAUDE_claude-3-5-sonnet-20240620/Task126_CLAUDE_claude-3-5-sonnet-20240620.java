
import java.awt.Desktop;
import java.io.IOException;
import java.net.URI;
import java.net.URISyntaxException;
import java.util.Scanner;

public class UserRedirect {
    public static void main(String[] args) {
        System.out.println("Select a destination:");
        System.out.println("1. Google");
        System.out.println("2. YouTube");
        System.out.println("3. Wikipedia");
        System.out.println("4. GitHub");

        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter your choice (1-4): ");
        String choice = scanner.nextLine();

        String url;
        switch (choice) {
            case "1":
                url = "https://www.google.com";
                break;
            case "2":
                url = "https://www.youtube.com";
                break;
            case "3":
                url = "https://www.wikipedia.org";
                break;
            case "4":
                url = "https://www.github.com";
                break;
            default:
                System.out.println("Invalid choice. Please try again.");
                scanner.close();
                return;
        }

        try {
            Desktop.getDesktop().browse(new URI(url));
        } catch (IOException | URISyntaxException e) {
            e.printStackTrace();
        }

        scanner.close();
    }
}
