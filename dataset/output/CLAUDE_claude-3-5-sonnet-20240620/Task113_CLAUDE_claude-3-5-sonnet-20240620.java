
import java.util.Scanner;

public class StringConcatenation {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        StringBuilder result = new StringBuilder();
        
        System.out.println("Enter strings to concatenate (type \'done\' to finish):");
        
        while (true) {
            String input = scanner.nextLine();
            if (input.equalsIgnoreCase("done")) {
                break;
            }
            result.append(input);
        }
        
        System.out.println("Concatenated string: " + result.toString());
        scanner.close();
    }
}
