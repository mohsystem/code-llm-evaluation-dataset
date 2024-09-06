import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Task66_MISTRAL_codestral_latest {
    public static void main(String[] args) {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        System.out.print("Enter a bash shell command: ");
        try {
            String command = reader.readLine();
            if (validateCommand(command)) {
                Process process = Runtime.getRuntime().exec(command);
                BufferedReader processReader = new BufferedReader(new InputStreamReader(process.getInputStream()));
                String line;
                while ((line = processReader.readLine()) != null) {
                    System.out.println(line);
                }
            } else {
                System.out.println("Invalid command");
            }
        } catch (IOException e) {
            System.out.println("Error: " + e.getMessage());
        }
    }

    private static boolean validateCommand(String command) {
        // Simple validation: check if command is not empty
        return !command.trim().isEmpty();
    }
}