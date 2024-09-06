import java.util.regex.Pattern;

public class Task118_GEMINI_gemini_1_5_pro_001 {

  public static void main(String[] args) {
    String ipAddress = "192.168.1.1"; // Example IP address
    if (isValidIP(ipAddress)) {
      System.out.println("Valid IP address");
    } else {
      System.out.println("Invalid IP address");
    }
  }

  public static boolean isValidIP(String ip) {
    String regex =
        "^((25[0-5]|2[0-4][0-9]|1[0-9][0-9]|[1-9]?[0-9])\\.){3}(25[0-5]|2[0-4][0-9]|1[0-9][0-9]|[1-9]?[0-9])$";
    return Pattern.matches(regex, ip);
  }
}