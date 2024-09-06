
import java.util.Scanner;
import java.util.regex.Pattern;

public class Task44_CLAUDE_claude_3_5_sonnet_20240620 {
    private static final Pattern VALID_INPUT_PATTERN = Pattern.compile("^[a-zA-Z0-9\\\\s]+$");

    public static boolean validateInput(String input) {
        return VALID_INPUT_PATTERN.matcher(input).matches();
    }

    public static String processInput(String input) {
        return input.toUpperCase();
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        while (true) {
            System.out.print("Enter some text (alphanumeric characters and spaces only): ");
            String userInput = scanner.nextLine();

            if (validateInput(userInput)) {
                String processedInput = processInput(userInput);
                System.out.println("Processed input: " + processedInput);
                break;
            } else {
                System.out.println("Invalid input. Please try again.");
            }
        }

        scanner.close();
    }
}
