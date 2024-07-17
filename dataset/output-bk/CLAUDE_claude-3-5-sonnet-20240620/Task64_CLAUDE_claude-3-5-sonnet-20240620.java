
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.net.URL;
import org.json.JSONObject;

public class JSONFetcher {
    public static void main(String[] args) {
        if (args.length != 1) {
            System.out.println("Usage: java JSONFetcher <url>");
            return;
        }

        try {
            String urlString = args[0];
            URL url = new URL(urlString);
            BufferedReader reader = new BufferedReader(new InputStreamReader(url.openStream()));
            StringBuilder jsonString = new StringBuilder();
            String line;
            while ((line = reader.readLine()) != null) {
                jsonString.append(line);
            }
            reader.close();

            JSONObject jsonObject = new JSONObject(jsonString.toString());
            System.out.println(jsonObject.toString(4));
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
