import java.util.regex.Pattern;

public class Task118_MISTRAL_codestral_latest {
    private static final Pattern IPV4_PATTERN =
            Pattern.compile("^((25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\\.){3}(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)$");

    public static boolean validate(final String ip) {
        return IPV4_PATTERN.matcher(ip).matches();
    }

    public static void main(String[] args) {
        System.out.println(validate("192.168.1.1"));  // true
        System.out.println(validate("256.168.1.1"));  // false
    }
}