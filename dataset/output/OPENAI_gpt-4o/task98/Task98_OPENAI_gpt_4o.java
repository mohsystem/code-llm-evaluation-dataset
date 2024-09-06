import java.util.Scanner;

public class Task98_OPENAI_gpt_4o {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter a number: ");
        String userInput = scanner.nextLine();
        try {
            int result = Integer.parseInt(userInput);
            System.out.println("Converted Integer: " + result);
        } catch (NumberFormatException e) {
            System.out.println("Error: Not a valid integer");
        }
        scanner.close();
    }
}