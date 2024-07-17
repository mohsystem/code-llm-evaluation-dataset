import java.io.IOException;
import java.util.Scanner;

public class Main {
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