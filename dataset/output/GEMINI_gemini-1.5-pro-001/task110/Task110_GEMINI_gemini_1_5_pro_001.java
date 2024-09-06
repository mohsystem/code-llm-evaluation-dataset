import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class Task110_GEMINI_gemini_1_5_pro_001 {
  public static boolean isValidUrl(String url) {
    String regex = "^(?:http|ftp)s?://"  // http:// or https://
        + "(?:(?:[A-Z0-9](?:[A-Z0-9-]{0,61}[A-Z0-9])?\\.)+(?:[A-Z]{2,6}\\.?|[A-Z0-9-]{2,}\\.?)|"  // domain...
        + "localhost|"  // localhost...
        + "\\d{1,3}\\.\\d{1,3}\\.\\d{1,3}\\.\\d{1,3})"  // ...or ip
        + "(?::\\d+)?"  // optional port
        + "(?:/?|[/?]\\S+)$";
    Pattern pattern = Pattern.compile(regex, Pattern.CASE_INSENSITIVE);
    Matcher matcher = pattern.matcher(url);
    return matcher.matches();
  }

  public static void main(String[] args) {
    String url = System.console().readLine("Enter a URL: ");
    if (isValidUrl(url)) {
      System.out.println("Valid URL");
    } else {
      System.out.println("Invalid URL");
    }
  }
}