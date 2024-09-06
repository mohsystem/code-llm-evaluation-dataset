import java.util.Scanner;
import java.io.IOException;

public class Task39_MISTRAL_codestral_latest {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter the filename: ");
        String filename = scanner.nextLine();
        try {
            Runtime.getRuntime().exec("cat " + filename);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}