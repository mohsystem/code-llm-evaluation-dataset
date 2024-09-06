import java.util.regex.Matcher;
import java.util.regex.Pattern;
import java.util.Scanner;

public class Task109_MISTRAL_codestral_latest {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter your input: ");
        String userInput = scanner.nextLine();
        if (validateInput(userInput)) {
            System.out.println("Input is valid");
        } else {
            System.out.println("Input is invalid");
        }
    }

    public static boolean validateInput(String userInput) {
        Pattern pattern = Pattern.compile("^[a-zA-Z0-9_]+$");
        Matcher matcher = pattern.matcher(userInput);
        return matcher.matches();
    }
}