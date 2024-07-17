
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.net.HttpURLConnection;
import java.net.URL;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class WebTitleExtractor {
    public static void main(String[] args) {
        if (args.length != 1) {
            System.out.println("Usage: java WebTitleExtractor <URL>");
            return;
        }

        String url = args[0];
        try {
            String title = extractTitle(url);
            System.out.println("Page Title: " + title);
        } catch (Exception e) {
            System.out.println("Error: " + e.getMessage());
        }
    }

    public static String extractTitle(String urlString) throws Exception {
        URL url = new URL(urlString);
        HttpURLConnection connection = (HttpURLConnection) url.openConnection();
        connection.setRequestMethod("GET");

        BufferedReader reader = new BufferedReader(new InputStreamReader(connection.getInputStream()));
        StringBuilder content = new StringBuilder();
        String line;

        while ((line = reader.readLine()) != null) {
            content.append(line);
        }
        reader.close();

        Pattern pattern = Pattern.compile("<title>(.*?)</title>");
        Matcher matcher = pattern.matcher(content.toString());

        if (matcher.find()) {
            return matcher.group(1);
        } else {
            return "Title not found";
        }
    }
}
