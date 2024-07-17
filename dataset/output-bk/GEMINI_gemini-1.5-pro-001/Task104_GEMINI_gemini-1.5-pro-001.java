import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        final int BUFFER_SIZE = 100;
        char[] buffer = new char[BUFFER_SIZE];
        int bufferIndex = 0;

        System.out.print("Enter input: ");
        String input = scanner.nextLine();

        for (int i = 0; i < input.length() && bufferIndex < BUFFER_SIZE; i++) {
            buffer[bufferIndex++] = input.charAt(i);
        }

        System.out.print("Buffer contents: ");
        for (int i = 0; i < bufferIndex; i++) {
            System.out.print(buffer[i]);
        }
        System.out.println();
    }
}