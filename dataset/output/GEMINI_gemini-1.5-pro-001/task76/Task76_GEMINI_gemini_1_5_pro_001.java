import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.URL;
import java.net.URLConnection;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class Task76_GEMINI_gemini_1_5_pro_001 {
    public static void main(String[] args) {
        if (args.length < 1) {
            System.out.println("Usage: java Task76_GEMINI_gemini_1_5_pro_001 <url>");
            return;
        }

        String url = args[0];

        try {
            URLConnection connection = new URL(url).openConnection();
            BufferedReader reader = new BufferedReader(new InputStreamReader(connection.getInputStream()));
            String line;
            StringBuilder html = new StringBuilder();
            while ((line = reader.readLine()) != null) {
                html.append(line);
            }
            reader.close();

            String title = extractTitle(html.toString());
            System.out.println(title);
        } catch (IOException e) {
            System.out.println("Error: " + e.getMessage());
        }
    }

    private static String extractTitle(String html) {
        Pattern pattern = Pattern.compile("<title>(.*?)</title>");
        Matcher matcher = pattern.matcher(html);
        if (matcher.find()) {
            return matcher.group(1).trim();
        } else {
            return "";
        }
    }
}