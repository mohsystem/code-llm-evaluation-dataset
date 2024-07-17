import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class CleanPhoneNumber {

    public static String cleanPhoneNumber(String phoneNumber) {
        String cleanedNumber = phoneNumber.replaceAll("[^0-9]", "");
        if (cleanedNumber.length() == 11 && cleanedNumber.startsWith("1")) {
            cleanedNumber = cleanedNumber.substring(1);
        }
        return cleanedNumber;
    }

    public static void main(String[] args) {
        String[] phoneNumbers = {
                "+1 (613)-995-0253",
                "613-995-0253",
                "1 613 995 0253",
                "613.995.0253"
        };

        for (String phoneNumber : phoneNumbers) {
            String cleanedNumber = cleanPhoneNumber(phoneNumber);
            System.out.println(cleanedNumber);
        }
    }
}