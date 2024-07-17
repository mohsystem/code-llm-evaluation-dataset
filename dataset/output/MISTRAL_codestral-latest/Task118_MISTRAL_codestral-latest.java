import java.util.regex.Pattern;

public class IPValidator {
    private static final String IPV4_REGEX =
            "^(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\\." +
            "(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\\." +
            "(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\\." +
            "(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)$";

    private static final Pattern IPV4_PATTERN = Pattern.compile(IPV4_REGEX);

    public static boolean isValidIP(String ip) {
        return IPV4_PATTERN.matcher(ip).matches();
    }

    public static void main(String[] args) {
        String ip = "192.168.1.1";
        if (isValidIP(ip)) {
            System.out.println(ip + " is a valid IP address.");
        } else {
            System.out.println(ip + " is not a valid IP address.");
        }
    }
}