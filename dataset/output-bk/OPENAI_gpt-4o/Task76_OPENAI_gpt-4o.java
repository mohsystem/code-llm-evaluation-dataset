import java.io.*;
import java.net.*;
import java.util.regex.*;
import javax.net.ssl.HttpsURLConnection;

class HTTPCall {
    public static void main(String[] args) {
        if (args.length > 0) {
            String urlString = args[0];
            try {
                URL url = new URL(urlString);
                HttpsURLConnection conn = (HttpsURLConnection) url.openConnection();
                BufferedReader in = new BufferedReader(new InputStreamReader(conn.getInputStream()));
                String inputLine;
                StringBuilder content = new StringBuilder();
                while ((inputLine = in.readLine()) != null) {
                    content.append(inputLine);
                }
                in.close();
                String html = content.toString();
                Matcher matcher = Pattern.compile("<title>(.*?)</title>").matcher(html);
                if (matcher.find()) {
                    System.out.println(matcher.group(1));
                }
            } catch (Exception e) {
                e.printStackTrace();
            }
        }
    }
}