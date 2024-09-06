// Java
import java.util.Scanner;

public class Task113_MISTRAL_codestral_latest {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        StringBuilder concatenatedString = new StringBuilder();

        while (true) {
            System.out.print("Enter a string (or press enter to finish): ");
            String userInput = scanner.nextLine();
            if (userInput.isEmpty()) {
                break;
            }
            concatenatedString.append(userInput);
        }

        System.out.println("Concatenated string: " + concatenatedString.toString());
    }
}