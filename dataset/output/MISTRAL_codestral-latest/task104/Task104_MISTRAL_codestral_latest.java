// Java
import java.util.Scanner;

public class Task104_MISTRAL_codestral_latest {
    public static void main(String[] args) {
        int bufferSize = 10;
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter a string: ");
        String userInput = scanner.nextLine();
        if (userInput.length() > bufferSize) {
            userInput = userInput.substring(0, bufferSize);
        }
        System.out.println("Truncated input: " + userInput);
    }
}