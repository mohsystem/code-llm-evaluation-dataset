import java.io.IOException;
import java.net.URL;
import org.jsoup.Jsoup;
import org.jsoup.nodes.Document;

public class Task76_MISTRAL_codestral_latest {
    public static void main(String[] args) {
        String url = args[0];
        try {
            Document document = Jsoup.parse(new URL(url), 3000);
            String title = document.title();
            System.out.println("Page title is: " + title);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}