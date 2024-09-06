import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class Task182_PERPLEXITY_llama_3_sonar_large_32k_chat {
    public static void main(String[] args) {
        System.out.println(cleanPhoneNumber("+1 (613)-995-0253"));
        System.out.println(cleanPhoneNumber("613-995-0253"));
        System.out.println(cleanPhoneNumber("1 613 995 0253"));
        System.out.println(cleanPhoneNumber("613.995.0253"));
    }

    public static String cleanPhoneNumber(String phoneNumber) {
        String cleaned = phoneNumber.replaceAll("[^\\d]", "");
        if (cleaned.startsWith("1")) {
            cleaned = cleaned.substring(1);
        }
        return cleaned;
    }
}