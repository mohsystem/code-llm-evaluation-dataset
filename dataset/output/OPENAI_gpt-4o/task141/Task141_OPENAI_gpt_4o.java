import java.util.Scanner;

public class Task141_OPENAI_gpt_4o {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String input_str = scanner.nextLine();
        String reversed = new StringBuilder(input_str).reverse().toString();
        System.out.println(reversed);
    }
}