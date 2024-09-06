code here:
import java.util.Scanner;

public class Task159_PERPLEXITY_llama_3_sonar_large_32k_chat {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter the buffer size: ");
        int bufferSize = scanner.nextInt();
        int[] buffer = new int[bufferSize];
        for (int i = 0; i < bufferSize; i++) {
            buffer[i] = i;
        }
        while (true) {
            System.out.print("Enter the index to read from the buffer (or -1 to exit): ");
            int index = scanner.nextInt();
            if (index == -1) {
                break;
            }
            if (index < 0 || index >= bufferSize) {
                System.out.println("Invalid index");
            } else {
                System.out.println("Buffer[" + index + "] = " + buffer[index]);
            }
        }
    }
}