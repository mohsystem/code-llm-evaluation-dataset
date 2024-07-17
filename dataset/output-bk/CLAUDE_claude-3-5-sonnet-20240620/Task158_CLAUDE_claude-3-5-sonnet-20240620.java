
import java.io.IOException;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter data: ");
        String userInput = scanner.nextLine();
        scanner.close();
        
        try {
            Runtime.getRuntime().exec("cmd /c echo " + userInput);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
