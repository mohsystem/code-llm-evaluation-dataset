
import java.util.Scanner;

public class DynamicBufferReader {
    public static void main(String[] args) {
        int bufferSize = 100;
        char[] buffer = new char[bufferSize];
        
        // Fill buffer with some data
        for (int i = 0; i < bufferSize; i++) {
            buffer[i] = (char) (\'A\' + (i % 26));
        }
        
        Scanner scanner = new Scanner(System.in);
        
        while (true) {
            System.out.print("Enter an index to read (0-99), or -1 to exit: ");
            try {
                int index = scanner.nextInt();
                if (index == -1) {
                    break;
                }
                if (index >= 0 && index < bufferSize) {
                    System.out.println("Data at index " + index + ": " + buffer[index]);
                } else {
                    System.out.println("Invalid index. Please enter a number between 0 and 99.");
                }
            } catch (Exception e) {
                System.out.println("Invalid input. Please enter a number.");
                scanner.nextLine(); // Clear the input buffer
            }
        }
        
        System.out.println("Program terminated.");
        scanner.close();
    }
}
