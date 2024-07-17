
import java.util.regex.Pattern;
import java.util.regex.Matcher;

public class PhoneNumber {
    public static String cleanPhoneNumber(String phone) {
        // Remove all non-digit characters
        String cleaned = phone.replaceAll("\\\\D", "");
        
        // Remove country code if present
        if (cleaned.length() == 11 && cleaned.startsWith("1")) {
            cleaned = cleaned.substring(1);
        }
        
        // Check if the number is valid
        if (cleaned.length() != 10 || !Pattern.matches("^[2-9].*", cleaned)) {
            throw new IllegalArgumentException("Invalid phone number");
        }
        
        return cleaned;
    }

    public static void main(String[] args) {
        String[] testNumbers = {
            "+1 (613)-995-0253",
            "613-995-0253",
            "1 613 995 0253",
            "613.995.0253"
        };

        for (String number : testNumbers) {
            try {
                System.out.println(cleanPhoneNumber(number));
            } catch (IllegalArgumentException e) {
                System.out.println("Error: " + e.getMessage());
            }
        }
    }
}
