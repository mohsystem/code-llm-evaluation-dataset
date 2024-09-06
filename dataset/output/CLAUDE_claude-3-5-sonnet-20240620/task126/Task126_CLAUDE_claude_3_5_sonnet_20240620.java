
import java.awt.Desktop;
import java.io.IOException;
import java.net.URI;
import java.net.URISyntaxException;
import java.util.Scanner;

public class Task126_CLAUDE_claude_3_5_sonnet_20240620 {
    public static void main(String[] args) {
        System.out.println("Select a destination:");
        System.out.println("1. Google");
        System.out.println("2. YouTube");
        System.out.println("3. Wikipedia");

        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter your choice (1-3): ");
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
            default:
                System.out.println("Invalid choice. Please try again.");
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
