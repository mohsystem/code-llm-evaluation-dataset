// Java does not support OS commands directly, so we use Runtime class
import java.io.IOException;
import java.util.Scanner;

public class Task158_PERPLEXITY_llama_3_sonar_large_32k_chat {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter data: ");
        String data = scanner.nextLine();
        try {
            Runtime.getRuntime().exec("echo " + data + " > output.txt");
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}