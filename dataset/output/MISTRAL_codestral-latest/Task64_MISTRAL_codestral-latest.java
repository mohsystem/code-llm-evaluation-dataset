import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.net.URL;
import org.json.JSONObject;

public class Main {
    public static void main(String[] args) {
        if (args.length == 0) {
            System.out.println("Please provide a URL as a command line argument.");
            return;
        }

        String url = args[0];
        try {
            JSONObject json = readJsonFromUrl(url);
            System.out.println(json.toString(4));
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    private static String readAll(BufferedReader rd) throws Exception {
        StringBuilder sb = new StringBuilder();
        int cp;
        while ((cp = rd.read()) != -1) {
            sb.append((char) cp);
        }
        return sb.toString();
    }

    public static JSONObject readJsonFromUrl(String url) throws Exception {
        BufferedReader rd = new BufferedReader(new InputStreamReader(new URL(url).openStream()));
        String jsonText = readAll(rd);
        JSONObject json = new JSONObject(jsonText);
        return json;
    }
}