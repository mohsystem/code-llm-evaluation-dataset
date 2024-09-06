
import java.util.Scanner;
import java.util.regex.Pattern;

public class Task118_CLAUDE_claude_3_5_sonnet_20240620 {
    public static boolean validateIP(String ip) {
        String pattern = "^(\\\\d{1,3}\\\\.){3}\\\\d{1,3}$";
        if (!Pattern.matches(pattern, ip)) {
            return false;
        }
        String[] octets = ip.split("\\\\.");
        for (String octet : octets) {
            int value = Integer.parseInt(octet);
            if (value < 0 || value > 255) {
                return false;
            }
        }
        return true;
    }

    public static void processIP(String ip) {
        if (validateIP(ip)) {
            String[] octets = ip.split("\\\\.");
            int firstOctet = Integer.parseInt(octets[0]);
            String classType = "";
            if (firstOctet >= 1 && firstOctet <= 126) {
                classType = "A";
            } else if (firstOctet >= 128 && firstOctet <= 191) {
                classType = "B";
            } else if (firstOctet >= 192 && firstOctet <= 223) {
                classType = "C";
            } else if (firstOctet >= 224 && firstOctet <= 239) {
                classType = "D";
            } else if (firstOctet >= 240 && firstOctet <= 255) {
                classType = "E";
            }
            System.out.println("Valid IP address. Class: " + classType);
        } else {
            System.out.println("Invalid IP address");
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter an IP address: ");
        String ip = scanner.nextLine();
        processIP(ip);
        scanner.close();
    }
}
