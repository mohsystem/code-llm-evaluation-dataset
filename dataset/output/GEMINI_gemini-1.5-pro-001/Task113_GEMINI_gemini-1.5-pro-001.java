import java.util.Scanner;

public class ConcatenateStrings {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        StringBuilder concatenatedString = new StringBuilder();

        while (true) {
            System.out.print("Enter a string (or type 'quit' to exit): ");
            String inputString = scanner.nextLine();

            if (inputString.equalsIgnoreCase("quit")) {
                break;
            }

            concatenatedString.append(inputString);
        }

        System.out.println("Concatenated string: " + concatenatedString.toString());
    }
}