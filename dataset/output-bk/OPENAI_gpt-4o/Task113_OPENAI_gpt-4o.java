import java.util.Scanner;

public class ConcatenateStrings {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter number of strings to concatenate:");
        int n = scanner.nextInt();
        scanner.nextLine();  // Consume the newline
        StringBuilder result = new StringBuilder();

        for(int i = 0; i < n; i++) {
            System.out.println("Enter string " + (i + 1) + ":");
            String str = scanner.nextLine();
            result.append(str);
        }

        System.out.println("Concatenated string: " + result.toString());
    }
}