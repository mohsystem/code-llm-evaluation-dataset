
import java.util.Scanner;

public class Task104_CLAUDE_claude_3_5_sonnet_20240620 {
    private static final int BUFFER_SIZE = 100;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        StringBuilder buffer = new StringBuilder(BUFFER_SIZE);

        while (true) {
            System.out.print("Enter text (or 'q' to quit): ");
            String userInput = scanner.nextLine();

            if (userInput.equalsIgnoreCase("q")) {
                break;
            }

            if (buffer.length() + userInput.length() <= BUFFER_SIZE) {
                buffer.append(userInput);
                System.out.println("Buffer content: " + buffer.toString());
            } else {
                System.out.println("Error: Buffer overflow. Cannot add more than " + BUFFER_SIZE + " characters.");
            }
        }

        System.out.println("Final buffer content: " + buffer.toString());
        scanner.close();
    }
}
