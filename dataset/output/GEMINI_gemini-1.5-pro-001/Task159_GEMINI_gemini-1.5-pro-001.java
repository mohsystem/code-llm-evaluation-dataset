import java.util.Scanner;

public class DynamicBuffer {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        try {
            System.out.print("Enter the buffer size: ");
            int bufferSize = scanner.nextInt();

            int[] buffer = new int[bufferSize];

            for (int i = 0; i < bufferSize; i++) {
                System.out.print("Enter data for index " + i + ": ");
                buffer[i] = scanner.nextInt();
            }

            while (true) {
                System.out.print("Enter an index to read (or -1 to exit): ");
                int index = scanner.nextInt();

                if (index == -1) {
                    break;
                }

                if (index >= 0 && index < bufferSize) {
                    System.out.println("Data at index " + index + ": " + buffer[index]);
                } else {
                    System.out.println("Index out of range.");
                }
            }
        } catch (java.util.InputMismatchException e) {
            System.out.println("Invalid input. Please enter an integer.");
        } finally {
            scanner.close();
        }
    }
}