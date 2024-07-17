
import java.util.Scanner;

public class InputOperations {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        System.out.print("Enter a number between 1 and 100: ");
        int number = getValidNumber(scanner, 1, 100);
        
        System.out.print("Enter your name (max 50 characters): ");
        String name = getValidString(scanner, 50);
        
        System.out.println("Hello, " + name + "!");
        System.out.println("Your number squared is: " + (number * number));
        System.out.println("Your number cubed is: " + (number * number * number));
        
        scanner.close();
    }
    
    private static int getValidNumber(Scanner scanner, int min, int max) {
        while (true) {
            try {
                int input = Integer.parseInt(scanner.nextLine());
                if (input >= min && input <= max) {
                    return input;
                } else {
                    System.out.print("Please enter a number between " + min + " and " + max + ": ");
                }
            } catch (NumberFormatException e) {
                System.out.print("Invalid input. Please enter a number: ");
            }
        }
    }
    
    private static String getValidString(Scanner scanner, int maxLength) {
        while (true) {
            String input = scanner.nextLine().trim();
            if (!input.isEmpty() && input.length() <= maxLength) {
                return input;
            } else {
                System.out.print("Please enter a non-empty string with max " + maxLength + " characters: ");
            }
        }
    }
}
