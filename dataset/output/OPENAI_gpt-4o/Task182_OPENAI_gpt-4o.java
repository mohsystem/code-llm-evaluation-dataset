import java.util.regex.*;

public class PhoneNumberCleanup {
    public static String cleanPhoneNumber(String phone) {
        phone = phone.replaceAll("\\D", "");
        if (phone.startsWith("1") && phone.length() == 11) {
            phone = phone.substring(1);
        }
        return phone;
    }

    public static void main(String[] args) {
        String[] numbers = {
            "+1 (613)-995-0253",
            "613-995-0253",
            "1 613 995 0253",
            "613.995.0253"
        };

        for (String number : numbers) {
            System.out.println(cleanPhoneNumber(number));
        }
    }
}