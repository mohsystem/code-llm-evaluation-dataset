code here:
// Java does not have a built-in way to open a web browser, so we'll use the Desktop class
import java.awt.Desktop;
import java.io.IOException;
import java.net.URI;

public class Task126_PERPLEXITY_llama_3_sonar_large_32k_chat {
    public static void main(String[] args) {
        System.out.print("Enter 'google' to go to Google, 'facebook' to go to Facebook, or 'youtube' to go to YouTube: ");
        String user_input = System.console().readLine();
        if (user_input.equals("google")) {
            openWebpage("https://www.google.com");
        } else if (user_input.equals("facebook")) {
            openWebpage("https://www.facebook.com");
        } else if (user_input.equals("youtube")) {
            openWebpage("https://www.youtube.com");
        } else {
            System.out.println("Invalid input. Please try again.");
        }
    }

    public static void openWebpage(String url) {
        try {
            URI uri = new URI(url);
            Desktop desktop = Desktop.isDesktopSupported() ? Desktop.getDesktop() : null;
            if (desktop != null && desktop.isSupported(Desktop.Action.BROWSE)) {
                desktop.browse(uri);
            }
        } catch (Exception e) {
            System.out.println("Error opening webpage: " + e.getMessage());
        }
    }
}