import java.util.Scanner;

public class Task113_OPENAI_gpt_4o {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter first string: ");
        String inputStr1 = scanner.nextLine();
        System.out.print("Enter second string: ");
        String inputStr2 = scanner.nextLine();
        String result = inputStr1 + inputStr2;
        System.out.println("Concatenated result: " + result);
    }
}