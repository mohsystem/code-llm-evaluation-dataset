
import java.util.regex.Pattern;
import java.util.Scanner;

public class IPValidator {
    public static boolean isValidIPv4(String ip) {
        String[] octets = ip.split("\\\\.");
        if (octets.length != 4) {
            return false;
        }
        for (String octet : octets) {
            try {
                int num = Integer.parseInt(octet);
                if (num < 0 || num > 255 || (octet.length() > 1 && octet.startsWith("0"))) {
                    return false;
                }
            } catch (NumberFormatException e) {
                return false;
            }
        }
        return true;
    }

    public static boolean isValidIPv6(String ip) {
        String regex = "([0-9a-fA-F]{1,4}:){7}([0-9a-fA-F]{1,4})";
        return Pattern.matches(regex, ip);
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter an IP address: ");
        String ip = scanner.nextLine();
        
        if (isValidIPv4(ip)) {
            System.out.println("Valid IPv4 address");
        } else if (isValidIPv6(ip)) {
            System.out.println("Valid IPv6 address");
        } else {
            System.out.println("Invalid IP address");
        }
        scanner.close();
    }
}
