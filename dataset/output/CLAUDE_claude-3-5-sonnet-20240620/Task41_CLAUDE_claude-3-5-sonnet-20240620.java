
import java.util.Scanner;

public class SafeStringProcessor {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter a string: ");
        String input = scanner.nextLine();
        scanner.close();

        // Process the input string
        String processed = processString(input);
        System.out.println("Processed string: " + processed);
    }

    private static String processString(String input) {
        // Example processing: convert to uppercase
        return input.toUpperCase();
    }
}
