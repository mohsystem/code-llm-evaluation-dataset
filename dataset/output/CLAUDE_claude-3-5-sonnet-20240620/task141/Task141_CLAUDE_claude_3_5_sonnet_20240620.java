
import java.util.Scanner;

public class Task141_CLAUDE_claude_3_5_sonnet_20240620 {
    public static String reverseString(String s) {
        return new StringBuilder(s).reverse().toString();
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter a string: ");
        String input = scanner.nextLine();
        System.out.println("Reversed string: " + reverseString(input));
        scanner.close();
    }
}
