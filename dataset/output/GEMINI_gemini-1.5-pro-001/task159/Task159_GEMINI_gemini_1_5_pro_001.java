import java.util.Scanner;

public class Task159_GEMINI_gemini_1_5_pro_001 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        try {
            System.out.print("Enter the size of the buffer: ");
            int size = scanner.nextInt();

            String[] buffer = new String[size];

            for (int i = 0; i < size; i++) {
                System.out.print("Enter data for index " + i + ": ");
                buffer[i] = scanner.next();
            }

            while (true) {
                System.out.print("Enter an index to read data (or -1 to exit): ");
                int index = scanner.nextInt();

                if (index == -1) {
                    break;
                } else if (index >= 0 && index < size) {
                    System.out.println("Data at index " + index + ": " + buffer[index]);
                } else {
                    System.out.println("Index out of range.");
                }
            }
        } catch (Exception e) {
            System.out.println("Invalid input. Please enter integers only.");
        }
    }
}