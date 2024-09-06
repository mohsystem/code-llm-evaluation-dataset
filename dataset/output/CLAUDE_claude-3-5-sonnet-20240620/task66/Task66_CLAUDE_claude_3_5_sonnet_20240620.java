
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Scanner;
import java.util.regex.Pattern;

public class Task66_CLAUDE_claude_3_5_sonnet_20240620 {
    public static boolean validateCommand(String cmd) {
        if (cmd.trim().isEmpty() || Pattern.compile("(rm|sudo|mv|cp|chmod|chown)").matcher(cmd).find()) {
            return false;
        }
        return true;
    }

    public static String executeCommand(String cmd) {
        StringBuilder output = new StringBuilder();
        try {
            Process process = Runtime.getRuntime().exec(new String[]{"bash", "-c", cmd});
            BufferedReader reader = new BufferedReader(new InputStreamReader(process.getInputStream()));
            String line;
            while ((line = reader.readLine()) != null) {
                output.append(line).append("\\n");
            }
            process.waitFor();
        } catch (Exception e) {
            return "Error executing command: " + e.getMessage();
        }
        return output.toString();
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        while (true) {
            System.out.print("Enter a bash command (or 'exit' to quit): ");
            String userInput = scanner.nextLine();
            if (userInput.equalsIgnoreCase("exit")) {
                break;
            }
            if (validateCommand(userInput)) {
                String output = executeCommand(userInput);
                System.out.println("Output: " + output);
            } else {
                System.out.println("Invalid or potentially dangerous command. Please try again.");
            }
        }
        scanner.close();
    }
}
