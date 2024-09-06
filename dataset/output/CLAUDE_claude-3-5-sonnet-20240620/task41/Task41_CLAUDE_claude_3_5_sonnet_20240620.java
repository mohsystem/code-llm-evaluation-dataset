
import java.util.Scanner;

public class Task41_CLAUDE_claude_3_5_sonnet_20240620 {
    public static void processInput(String input) {
        // Process the input (example: print it back)
        System.out.println("Processed input: " + input);
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter a string (max 100 characters): ");
        
        // Read input and limit to 100 characters
        String userInput = scanner.nextLine();
        if (userInput.length() > 100) {
            userInput = userInput.substring(0, 100);
        }
        
        processInput(userInput);
        scanner.close();
    }
}
