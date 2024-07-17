import java.util.Scanner;

public class ResourceAccess {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter your choice: ");
        String userInput = scanner.nextLine();

        if (userInput.equals("option1")) {
            System.out.println("Accessing resource 1...");
        } else if (userInput.equals("option2")) {
            System.out.println("Accessing resource 2...");
        } else {
            System.out.println("Invalid choice.");
        }
    }
}