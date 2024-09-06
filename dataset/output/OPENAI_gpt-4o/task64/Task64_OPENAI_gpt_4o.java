import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.net.HttpURLConnection;
import java.net.URL;
import org.json.JSONObject;

public class Task64_OPENAI_gpt_4o {
    public static void main(String[] args) {
        if (args.length != 1) {
            System.out.println("Usage: java Task64_OPENAI_gpt_4o <URL>");
            System.exit(1);
        }

        String urlString = args[0];

        try {
            URL url = new URL(urlString);
            HttpURLConnection conn = (HttpURLConnection) url.openConnection();
            conn.setRequestMethod("GET");

            BufferedReader in = new BufferedReader(new InputStreamReader(conn.getInputStream()));
            String inputLine;
            StringBuffer content = new StringBuffer();

            while ((inputLine = in.readLine()) != null) {
                content.append(inputLine);
            }

            in.close();

            JSONObject jsonObject = new JSONObject(content.toString());
            System.out.println(jsonObject.toString(4));

        } catch (Exception e) {
            System.out.println("Failed to fetch or parse JSON: " + e.getMessage());
        }
    }
}