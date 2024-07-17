import java.util.Scanner;

public class StringOperations {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter a string: ");
        String inputString = scanner.nextLine();

        // Copy the string
        String copiedString = inputString;

        // Concatenate the string with itself
        String concatenatedString = inputString + inputString;

        // Reverse the string
        String reversedString = new StringBuilder(inputString).reverse().toString();

        // Convert the string to uppercase
        String uppercaseString = inputString.toUpperCase();

        // Convert the string to lowercase
        String lowercaseString = inputString.toLowerCase();

        System.out.println("Copied string: " + copiedString);
        System.out.println("Concatenated string: " + concatenatedString);
        System.out.println("Reversed string: " + reversedString);
        System.out.println("Uppercase string: " + uppercaseString);
        System.out.println("Lowercase string: " + lowercaseString);
    }
}