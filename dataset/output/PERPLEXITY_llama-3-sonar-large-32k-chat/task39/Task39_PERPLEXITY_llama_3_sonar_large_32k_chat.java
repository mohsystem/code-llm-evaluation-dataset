import java.io.IOException;
import java.util.Scanner;

public class Task39_PERPLEXITY_llama_3_sonar_large_32k_chat {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter a filename: ");
        String filename = scanner.nextLine();
        try {
            Runtime.getRuntime().exec("cat " + filename);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}