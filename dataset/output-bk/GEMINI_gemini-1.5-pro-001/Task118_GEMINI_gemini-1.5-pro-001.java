import java.util.regex.Pattern;

public class ValidateIP {
    public static void main(String[] args) {
        String ipAddress = "192.168.1.1";
        if (isValidIP(ipAddress)) {
            System.out.println(ipAddress + " is a valid IP address.");
        } else {
            System.out.println(ipAddress + " is not a valid IP address.");
        }
    }

    public static boolean isValidIP(String ipAddress) {
        String ipPattern = "^(([0-9]|[1-9][0-9]|1[0-9]{2}|2[0-4][0-9]|25[0-5])\\.){3}([0-9]|[1-9][0-9]|1[0-9]{2}|2[0-4][0-9]|25[0-5])$";
        return Pattern.matches(ipPattern, ipAddress);
    }
}