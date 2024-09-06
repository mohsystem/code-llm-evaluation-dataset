import java.util.Scanner;
import java.io.IOException;

public class Task158_MISTRAL_codestral_latest {
    public static void main(String[] args) throws IOException {
        // Create a Scanner object for user input
        Scanner scanner = new Scanner(System.in);

        // Get user input
        System.out.println("Enter data for OS command: ");
        String userInput = scanner.nextLine();

        // Construct the OS command
        String command = "your_command_here " + userInput;

        // Execute the command
        Runtime.getRuntime().exec(command);
    }
}