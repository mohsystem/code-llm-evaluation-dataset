import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.net.URL;
import java.net.URLConnection;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class Main {
    public static void main(String[] args) {
        if (args.length > 0) {
            String title = getPageTitle(args[0]);
            System.out.println("Page title: " + title);
        } else {
            System.out.println("Please provide an URL as a command line argument.");
        }
    }

    private static String getPageTitle(String url) {
        String title = "";
        try {
            URL website = new URL(url);
            URLConnection connection = website.openConnection();
            BufferedReader in = new BufferedReader(new InputStreamReader(connection.getInputStream()));

            String inputLine;
            Pattern pattern = Pattern.compile("<title>(.+?)</title>", Pattern.DOTALL);
            while ((inputLine = in.readLine()) != null) {
                Matcher matcher = pattern.matcher(inputLine);
                if (matcher.find()) {
                    title = matcher.group(1);
                    break;
                }
            }
            in.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
        return title;
    }
}