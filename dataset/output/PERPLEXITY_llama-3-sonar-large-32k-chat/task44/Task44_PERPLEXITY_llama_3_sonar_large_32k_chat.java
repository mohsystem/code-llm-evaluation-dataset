import java.util.InputMismatchException;
import java.util.Scanner;

public class Task44_PERPLEXITY_llama_3_sonar_large_32k_chat {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String inputStr = getUserInput(scanner, "Enter a string: ");
        try {
            validateInput(inputStr);
            System.out.println("Input is valid");
            System.out.println("Upper case: " + inputStr.toUpperCase());
            System.out.println("Lower case: " + inputStr.toLowerCase());
        } catch (Exception e) {
            System.out.println("Error: " + e.getMessage());
        }
    }

    public static String getUserInput(Scanner scanner, String prompt) {
        while (true) {
            try {
                System.out.print(prompt);
                return scanner.next();
            } catch (InputMismatchException e) {
                System.out.println("Invalid input. Please try again.");
                scanner.next(); // clear the invalid input
            }
        }
    }

    public static void validateInput(String inputStr) throws Exception {
        if (!inputStr.matches("[a-zA-Z]+")) {
            throw new Exception("Input should only contain alphabets");
        }
    }
}