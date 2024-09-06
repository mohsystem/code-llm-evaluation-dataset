import java.util.Scanner;

public class Task141_PERPLEXITY_llama_3_sonar_large_32k_chat {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter a string: ");
        String s = scanner.nextLine();
        String reversed = new StringBuilder(s).reverse().toString();
        System.out.println("Reversed string: " + reversed);
    }
}