import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter a string: ");
        byte[] buffer = new byte[10];
        byte[] input = scanner.nextLine().getBytes();

        if (input.length > buffer.length) {
            System.out.println("Input is too long for the buffer.");
        } else {
            System.arraycopy(input, 0, buffer, 0, input.length);
            System.out.println("Input stored in buffer: " + new String(buffer));
        }
    }
}