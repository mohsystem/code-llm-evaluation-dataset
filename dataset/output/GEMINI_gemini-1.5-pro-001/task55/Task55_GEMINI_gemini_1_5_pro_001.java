import java.util.regex.Matcher;
import java.util.regex.Pattern;
import java.util.Scanner;

public class Task55_GEMINI_gemini_1_5_pro_001 {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    System.out.print("Enter an email address: ");
    String email = scanner.nextLine();

    if (isValidEmail(email)) {
      System.out.println("Valid email address");
    } else {
      System.out.println("Invalid email address");
    }
  }

  public static boolean isValidEmail(String email) {
    String regex = "^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,}$";
    Pattern pattern = Pattern.compile(regex);
    Matcher matcher = pattern.matcher(email);
    return matcher.matches();
  }
}