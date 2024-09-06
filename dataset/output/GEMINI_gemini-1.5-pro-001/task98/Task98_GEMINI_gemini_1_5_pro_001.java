import java.util.Scanner;

public class Task98_GEMINI_gemini_1_5_pro_001 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter an integer: ");
        String userInput = scanner.nextLine();

        try {
            int integerValue = Integer.parseInt(userInput);
            System.out.println("Successfully converted to integer: " + integerValue);
        } catch (NumberFormatException e) {
            System.out.println("Invalid input. Please enter a valid integer.");
        }
    }
}