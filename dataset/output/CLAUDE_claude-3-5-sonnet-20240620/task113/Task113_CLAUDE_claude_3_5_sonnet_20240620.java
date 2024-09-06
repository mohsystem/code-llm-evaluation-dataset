
import java.util.ArrayList;
import java.util.Scanner;

public class Task113_CLAUDE_claude_3_5_sonnet_20240620 {
    public static void main(String[] args) {
        ArrayList<String> strings = new ArrayList<>();
        Scanner scanner = new Scanner(System.in);

        while (true) {
            System.out.print("Enter a string (or press Enter to finish): ");
            String s = scanner.nextLine();
            if (s.isEmpty()) {
                break;
            }
            strings.add(s);
        }

        String result = String.join(" ", strings);
        System.out.println("Concatenated string: " + result);

        scanner.close();
    }
}
