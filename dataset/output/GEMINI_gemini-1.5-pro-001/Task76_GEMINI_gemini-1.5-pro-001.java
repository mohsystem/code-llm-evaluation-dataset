import java.net.URL;
import java.net.HttpURLConnection;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class GetPageTitle {

    public static void main(String[] args) {
        if (args.length != 1) {
            System.out.println("Usage: java GetPageTitle <url>");
            return;
        }

        String url = args[0];
        try {
            String title = getPageTitle(url);
            System.out.println(title);
        } catch (Exception e) {
            System.out.println("Error: " + e.getMessage());
        }
    }

    public static String getPageTitle(String url) throws Exception {
        URL website = new URL(url);
        HttpURLConnection connection = (HttpURLConnection) website.openConnection();
        connection.setRequestMethod("GET");
        BufferedReader in = new BufferedReader(new InputStreamReader(connection.getInputStream()));
        String inputLine;
        StringBuilder content = new StringBuilder();
        while ((inputLine = in.readLine()) != null) {
            content.append(inputLine);
        }
        in.close();
        Pattern titlePattern = Pattern.compile("<title>(.*?)</title>", Pattern.CASE_INSENSITIVE);
        Matcher matcher = titlePattern.matcher(content.toString());
        if (matcher.find()) {
            return matcher.group(1).trim();
        } else {
            return null;
        }
    }
}