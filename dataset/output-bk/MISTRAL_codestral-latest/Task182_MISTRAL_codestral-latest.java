import java.util.regex.Pattern;

public class Main {
    public static void main(String[] args) {
        System.out.println(cleanPhoneNumber("+1 (613)-995-0253"));
    }

    public static String cleanPhoneNumber(String phoneNumber) {
        String cleanedNumber = phoneNumber.replaceAll("\\D", "");
        if (cleanedNumber.startsWith("1")) {
            cleanedNumber = cleanedNumber.substring(1);
        }
        return cleanedNumber;
    }
}