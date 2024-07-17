import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.URL;
import java.net.URLConnection;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class Main {
    public static void main(String[] args) {
        if (args.length != 1) {
            System.out.println("Usage: java Main <url>");
            return;
        }
        String url = args[0];
        try {
            URL obj = new URL(url);
            URLConnection conn = obj.openConnection();
            BufferedReader in = new BufferedReader(new InputStreamReader(conn.getInputStream()));
            String inputLine;
            StringBuilder response = new StringBuilder();
            while ((inputLine = in.readLine()) != null) {
                response.append(inputLine);
            }
            in.close();
            Pattern p = Pattern.compile("<title>(.*?)</title>");
            Matcher m = p.matcher(response.toString());
            if (m.find()) {
                System.out.println(m.group(1));
            } else {
                System.out.println("No title found");
            }
        } catch (IOException e) {
            System.out.println("Error: " + e.getMessage());
        }
    }
}