code here:
import java.util.Scanner;

public class Task104_PERPLEXITY_llama_3_sonar_large_32k_chat {
    public static void main(String[] args) {
        int bufferSize = 10;
        String[] buffer = new String[bufferSize];
        int index = 0;

        Scanner scanner = new Scanner(System.in);
        while (true) {
            System.out.print("Enter a value (or 'quit' to exit): ");
            String userInput = scanner.nextLine();
            if (userInput.equalsIgnoreCase("quit")) {
                break;
            }
            if (index < bufferSize) {
                buffer[index] = userInput;
                index++;
            } else {
                System.out.println("Buffer is full. Oldest value will be replaced.");
                for (int i = 0; i < bufferSize - 1; i++) {
                    buffer[i] = buffer[i + 1];
                }
                buffer[bufferSize - 1] = userInput;
            }
            System.out.print("Buffer: ");
            for (String s : buffer) {
                if (s != null) {
                    System.out.print(s + " ");
                }
            }
            System.out.println();
        }
    }
}