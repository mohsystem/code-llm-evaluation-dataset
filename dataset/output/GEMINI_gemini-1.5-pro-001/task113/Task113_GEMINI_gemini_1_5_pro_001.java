import java.util.Scanner;

public class Task113_GEMINI_gemini_1_5_pro_001 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter the number of strings: ");
        int numStrings = scanner.nextInt();
        scanner.nextLine(); // Consume newline character

        String concatenatedString = "";
        for (int i = 0; i < numStrings; i++) {
            System.out.print("Enter string " + (i + 1) + ": ");
            String userString = scanner.nextLine();
            concatenatedString += userString;
        }
        System.out.println("Concatenated string: " + concatenatedString);
    }
}