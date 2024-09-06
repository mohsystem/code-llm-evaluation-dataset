// Java code

import java.util.Scanner;

public class Task159_OPENAI_gpt_4o {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter the size of the buffer: ");
        int size = scanner.nextInt();
        int[] buffer = new int[size];

        while (true) {
            System.out.print("Enter index (-1 to quit): ");
            int index = scanner.nextInt();
            if (index == -1) {
                break;
            }
            if (index >= 0 && index < size) {
                System.out.println("Value at index " + index + ": " + buffer[index]);
            } else {
                System.out.println("Index out of bounds.");
            }
        }
    }
}