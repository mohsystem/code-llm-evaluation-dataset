import java.util.regex.Pattern;
import java.util.regex.Matcher;
import java.util.Scanner;

public class Task109_PERPLEXITY_llama_3_sonar_large_32k_chat {
    public static void main(String[] args) {
        Pattern pattern = Pattern.compile("^[a-zA-Z0-9_]{3,16}$");
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter a username: ");
        String user_input = scanner.nextLine();
        Matcher matcher = pattern.matcher(user_input);
        if (matcher.matches()) {
            System.out.println("Valid username");
        } else {
            System.out.println("Invalid username");
        }
    }
}