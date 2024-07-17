
import java.util.Scanner;
import java.util.regex.Pattern;
import java.util.regex.Matcher;

public class InputValidator {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        System.out.print("Enter an email address: ");
        String email = scanner.nextLine();
        
        String emailRegex = "^[A-Za-z0-9+_.-]+@[A-Za-z0-9.-]+$";
        Pattern pattern = Pattern.compile(emailRegex);
        
        if (pattern.matcher(email).matches()) {
            System.out.println("Valid email address");
        } else {
            System.out.println("Invalid email address");
        }
        
        System.out.print("Enter a phone number (XXX-XXX-XXXX): ");
        String phone = scanner.nextLine();
        
        String phoneRegex = "^\\\\d{3}-\\\\d{3}-\\\\d{4}$";
        pattern = Pattern.compile(phoneRegex);
        
        if (pattern.matcher(phone).matches()) {
            System.out.println("Valid phone number");
        } else {
            System.out.println("Invalid phone number");
        }
        
        scanner.close();
    }
}
