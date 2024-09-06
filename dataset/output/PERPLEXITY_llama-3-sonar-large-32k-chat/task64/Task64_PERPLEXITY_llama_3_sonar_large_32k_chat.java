import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.URL;
import java.net.URLConnection;
import org.json.JSONObject;

public class Task64_PERPLEXITY_llama_3_sonar_large_32k_chat {
    public static JSONObject readJsonFromUrl(String url) throws IOException {
        URL urlObj = new URL(url);
        URLConnection connection = urlObj.openConnection();
        BufferedReader reader = new BufferedReader(new InputStreamReader(connection.getInputStream()));
        StringBuilder json = new StringBuilder();
        String line;
        while ((line = reader.readLine()) != null) {
            json.append(line);
        }
        return new JSONObject(json.toString());
    }

    public static void main(String[] args) {
        if (args.length != 1) {
            System.out.println("Usage: java Task64_PERPLEXITY_llama_3_sonar_large_32k_chat <url>");
            System.exit(1);
        }
        String url = args[0];
        try {
            JSONObject jsonObj = readJsonFromUrl(url);
            System.out.println(jsonObj);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}