import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Scanner;
import java.util.regex.Pattern;

public class ShellExecutor {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter shell command: ");
        String command = scanner.nextLine();
        
        if (isValidCommand(command)) {
            try {
                Process process = Runtime.getRuntime().exec(command);
                BufferedReader reader = new BufferedReader(new InputStreamReader(process.getInputStream()));
                String line = null;
                while ((line = reader.readLine()) != null) {
                    System.out.println(line);
                }
            } catch (Exception e) {
                e.printStackTrace();
            }
        } else {
            System.out.println("Invalid command.");
        }
        scanner.close();
    }

    private static boolean isValidCommand(String command) {
        // Simple validation: command should only contain letters, numbers, spaces, and standard shell characters
        String regex = "[a-zA-Z0-9\\s-_/.]+";
        return Pattern.matches(regex, command);
    }
}