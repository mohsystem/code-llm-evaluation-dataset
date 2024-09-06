import java.util.regex.Pattern;
import java.util.regex.Matcher;
import java.util.Scanner;

public class Task55_PERPLEXITY_llama_3_sonar_large_32k_chat {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter an email address: ");
        String email = scanner.nextLine();
        if (validateEmail(email)) {
            System.out.println("Valid email address");
        } else {
            System.out.println("Invalid email address");
        }
    }

    public static boolean validateEmail(String email) {
        String pattern = "^[a-zA-Z0-9_.+-]+@[a-zA-Z0-9-]+\\.[a-zA-Z0-9-.]+$";
        Pattern r = Pattern.compile(pattern);
        Matcher m = r.matcher(email);
        return m.find();
    }
}