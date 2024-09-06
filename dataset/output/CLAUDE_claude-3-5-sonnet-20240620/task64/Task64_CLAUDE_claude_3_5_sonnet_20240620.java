
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.net.URL;
import java.net.URLConnection;
import org.json.JSONObject;

public class Task64_CLAUDE_claude_3_5_sonnet_20240620 {
    public static JSONObject fetchJSON(String urlString) throws Exception {
        URL url = new URL(urlString);
        URLConnection connection = url.openConnection();
        BufferedReader reader = new BufferedReader(new InputStreamReader(connection.getInputStream()));
        StringBuilder jsonString = new StringBuilder();
        String line;
        while ((line = reader.readLine()) != null) {
            jsonString.append(line);
        }
        reader.close();
        return new JSONObject(jsonString.toString());
    }

    public static void main(String[] args) {
        if (args.length != 1) {
            System.out.println("Usage: java Task64_CLAUDE_claude_3_5_sonnet_20240620 <url>");
            System.exit(1);
        }

        String url = args[0];
        try {
            JSONObject jsonData = fetchJSON(url);
            System.out.println(jsonData.toString(2));
        } catch (Exception e) {
            System.out.println("Error: " + e.getMessage());
        }
    }
}
