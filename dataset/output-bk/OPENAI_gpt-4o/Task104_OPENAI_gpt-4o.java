import java.util.Scanner;

public class MultiLangInput {
    public static void main(String[] args) {
        int bufferSize = 10;
        char[] buffer = new char[bufferSize];
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter input (Java): ");
        String input = scanner.nextLine();
        for (int i = 0; i < input.length() && i < bufferSize; i++) {
            buffer[i] = input.charAt(i);
        }
        System.out.println("Buffer contents (Java): ");
        for (char c : buffer) {
            System.out.print(c);
        }
        System.out.println();
        
        run_C(bufferSize, input.toCharArray());
        run_CPP(bufferSize, input.toCharArray());
        run_Python(bufferSize, input.toCharArray());
    }

    public static void run_C(int bufferSize, char[] input) {
        System.out.println("Running C code:");
        // Simulate running the C code
        System.out.println("Buffer size (C): " + bufferSize);
        System.out.print("Input (C): ");
        for (char c : input) {
            System.out.print(c);
        }
        System.out.println();
    }

    public static void run_CPP(int bufferSize, char[] input) {
        System.out.println("Running C++ code:");
        // Simulate running the C++ code
        System.out.println("Buffer size (C++): " + bufferSize);
        System.out.print("Input (C++): ");
        for (char c : input) {
            System.out.print(c);
        }
        System.out.println();
    }

    public static void run_Python(int bufferSize, char[] input) {
        System.out.println("Running Python code:");
        // Simulate running the Python code
        System.out.println("Buffer size (Python): " + bufferSize);
        System.out.print("Input (Python): ");
        for (char c : input) {
            System.out.print(c);
        }
        System.out.println();
    }
}