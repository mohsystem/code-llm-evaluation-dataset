import java.util.regex.*;

public class Task118_OPENAI_gpt_4o {
    public static boolean validateIP(String ip) {
        String pattern = "^([0-9]{1,3}\\.){3}[0-9]{1,3}$";
        if (!Pattern.matches(pattern, ip)) {
            return false;
        }
        String[] parts = ip.split("\\.");
        for (String part : parts) {
            if (Integer.parseInt(part) < 0 || Integer.parseInt(part) > 255) {
                return false;
            }
        }
        return true;
    }

    public static void main(String[] args) {
        String[] ips = {"192.168.1.1", "256.256.256.256", "123.045.067.089"};
        System.out.print("Validated IPs: ");
        for (String ip : ips) {
            if (validateIP(ip)) {
                System.out.print(ip + " ");
            }
        }
    }
}