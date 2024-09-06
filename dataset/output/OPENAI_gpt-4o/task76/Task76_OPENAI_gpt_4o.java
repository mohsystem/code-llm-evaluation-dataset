import java.io.IOException;
import org.jsoup.Jsoup;
import org.jsoup.nodes.Document;

public class Task76_OPENAI_gpt_4o {
    public static void main(String[] args) {
        if (args.length != 1) {
            System.out.println("Usage: java Task76_OPENAI_gpt_4o <URL>");
            System.exit(1);
        }

        String url = args[0];
        try {
            Document doc = Jsoup.connect(url).get();
            String title = doc.title();

            System.out.println(title);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}