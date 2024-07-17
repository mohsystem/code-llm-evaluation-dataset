import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter the size of the buffer: ");
        int size = scanner.nextInt();
        int[] buffer = new int[size];

        System.out.println("Enter the index to read from the buffer: ");
        int index = scanner.nextInt();

        if (index >= 0 && index < size) {
            System.out.println("Value at index " + index + ": " + buffer[index]);
        } else {
            System.out.println("Invalid index.");
        }
    }
}