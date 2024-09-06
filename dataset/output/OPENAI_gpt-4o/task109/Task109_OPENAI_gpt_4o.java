import java.util.Scanner;
import java.util.regex.Pattern;

public class Task109_OPENAI_gpt_4o {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter something: ");
        String user_input = scanner.nextLine();
        
        if (Pattern.matches("^[a-zA-Z0-9_]+$", user_input)) {
            System.out.println("Valid input");
        } else {
            System.out.println("Invalid input");
        }
    }
}