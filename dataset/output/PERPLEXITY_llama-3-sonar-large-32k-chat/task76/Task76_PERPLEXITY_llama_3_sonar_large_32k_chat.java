import java.io.IOException;
import java.net.URI;
import java.net.http.HttpClient;
import java.net.http.HttpRequest;
import java.net.http.HttpResponse;
import org.jsoup.Jsoup;
import org.jsoup.nodes.Document;
import org.jsoup.nodes.Element;

public class Task76_PERPLEXITY_llama_3_sonar_large_32k_chat {
    public static void main(String[] args) {
        if (args.length != 1) {
            System.out.println("Usage: java Task76_PERPLEXITY_llama_3_sonar_large_32k_chat <url>");
            System.exit(1);
        }
        String url = args[0];
        try {
            HttpClient client = HttpClient.newHttpClient();
            HttpRequest request = HttpRequest.newBuilder()
                    .uri(URI.create(url))
                    .GET()
                    .build();
            HttpResponse<String> response = client.send(request, HttpResponse.BodyHandlers.ofString());
            Document doc = Jsoup.parse(response.body());
            Element title = doc.select("title").first();
            System.out.println(title.text());
        } catch (IOException | InterruptedException e) {
            e.printStackTrace();
        }
    }
}