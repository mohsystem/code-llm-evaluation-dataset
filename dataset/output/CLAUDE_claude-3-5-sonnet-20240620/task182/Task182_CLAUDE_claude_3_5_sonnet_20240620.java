
import java.util.regex.Pattern;

public class Task182_CLAUDE_claude_3_5_sonnet_20240620 {
    public static String cleanPhoneNumber(String phone) {
        String digits = phone.replaceAll("[^0-9]", "");
        if (digits.length() == 11 && digits.startsWith("1")) {
            return digits.substring(1);
        } else if (digits.length() == 10) {
            return digits;
        } else {
            throw new IllegalArgumentException("Invalid phone number");
        }
    }

    public static void main(String[] args) {
        try {
            System.out.println(cleanPhoneNumber("+1 (613)-995-0253"));
            System.out.println(cleanPhoneNumber("613-995-0253"));
            System.out.println(cleanPhoneNumber("1 613 995 0253"));
            System.out.println(cleanPhoneNumber("613.995.0253"));
        } catch (IllegalArgumentException e) {
            System.out.println("Error: " + e.getMessage());
        }
    }
}
