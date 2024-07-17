import java.util.Scanner;

public class DynamicBuffer {
    public static void main(String[] args) {
        int size = 10;
        byte[] buffer = new byte[size];

        // Fill the buffer with some data
        for (int i = 0; i < size; i++) {
            buffer[i] = (byte) ('A' + i);
        }

        Scanner scanner = new Scanner(System.in);

        // Allow the user to read data from the buffer
        while (true) {
            System.out.print("Enter index to read (0-" + (size-1) + ") or -1 to exit: ");
            int index = scanner.nextInt();

            if (index == -1) {
                break;
            }

            if (index >= 0 && index < size) {
                System.out.println("Data at index " + index + ": " + (char) buffer[index]);
            } else {
                System.out.println("Index out of bounds");
            }
        }
        scanner.close();
    }
}