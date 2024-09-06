import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.URL;
import org.json.JSONObject; // You may need to add a JSON library to your project

public class Task64_GEMINI_gemini_1_5_pro_001 {
    public static void main(String[] args) {
        if (args.length != 1) {
            System.out.println("Usage: java Task64_GEMINI_gemini_1_5_pro_001 <url>");
            return;
        }
        String url = args[0];
        JSONObject jsonObject = getJsonFromUrl(url);

        if (jsonObject != null) {
            System.out.println(jsonObject.toString(2)); // Pretty print JSON
        }
    }

    public static JSONObject getJsonFromUrl(String url) {
        StringBuilder response = new StringBuilder();
        try (BufferedReader reader = new BufferedReader(new InputStreamReader(new URL(url).openStream()))) {
            String line;
            while ((line = reader.readLine()) != null) {
                response.append(line);
            }
            return new JSONObject(response.toString());
        } catch (IOException e) {
            System.err.println("Error fetching JSON from URL: " + e.getMessage());
            return null;
        }
    }
}