import java.util.regex.Pattern;

public class Task182_MISTRAL_codestral_latest {
    public static String cleanPhoneNumber(String phoneNumber) {
        String cleanedNumber = phoneNumber.replaceAll("\\D", "");
        if (cleanedNumber.startsWith("1")) {
            cleanedNumber = cleanedNumber.substring(1);
        }
        return cleanedNumber;
    }
}