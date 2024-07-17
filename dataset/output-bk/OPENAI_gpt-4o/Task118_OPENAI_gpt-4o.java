import java.util.regex.Matcher;
import java.util.regex.Pattern;

class Java {
    public static boolean isValidIPAddress(String ip) {
        String zeroTo255 = "([0-9]{1,2}|(0|1)[0-9]{2}|2[0-4][0-9]|25[0-5])";
        String regex = zeroTo255 + "\\." + zeroTo255 + "\\." + zeroTo255 + "\\." + zeroTo255;
        Pattern pattern = Pattern.compile(regex);
        if (ip == null) {
            return false;
        }
        Matcher matcher = pattern.matcher(ip);
        return matcher.matches();
    }

    public static void main(String[] args) {
        System.out.println(isValidIPAddress("192.168.0.1")); // true
        System.out.println(isValidIPAddress("256.256.256.256")); // false
    }
}