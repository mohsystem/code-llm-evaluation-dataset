import java.util.Scanner;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter phone number: ");
        String phoneNumber = scanner.nextLine();
        System.out.println(cleanPhoneNumber(phoneNumber));
    }

    public static String cleanPhoneNumber(String phoneNumber) {
        String cleanNumber = phoneNumber.replaceAll("[^\\d]", "");
        if (cleanNumber.startsWith("1")) {
            cleanNumber = cleanNumber.substring(1);
        }
        return cleanNumber;
    }
}