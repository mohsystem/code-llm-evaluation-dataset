import java.net.URL;
import java.net.MalformedURLException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import org.json.JSONObject;
import org.json.JSONException;

public class ReadJSONFromURL {

    public static JSONObject readJsonFromUrl(String url) throws IOException, JSONException {
        URL urlObject = new URL(url);
        BufferedReader reader = new BufferedReader(new InputStreamReader(urlObject.openStream()));
        StringBuilder json = new StringBuilder();
        String line;
        while ((line = reader.readLine()) != null) {
            json.append(line);
        }
        reader.close();
        return new JSONObject(json.toString());
    }

    public static void main(String[] args) {
        if (args.length != 1) {
            System.out.println("Usage: java ReadJSONFromURL <url>");
            System.exit(1);
        }

        String url = args[0];
        try {
            JSONObject jsonObject = readJsonFromUrl(url);
            System.out.println(jsonObject.toString(2)); // Pretty print with indentation
        } catch (MalformedURLException e) {
            System.out.println("Invalid URL: " + e.getMessage());
        } catch (IOException e) {
            System.out.println("Error reading from URL: " + e.getMessage());
        } catch (JSONException e) {
            System.out.println("Error parsing JSON: " + e.getMessage());
        }
    }
}