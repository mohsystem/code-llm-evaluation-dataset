import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class ExecuteCommand {

    public static boolean isValidCommand(String command) {
        for (char c : command.toCharArray()) {
            if (!Character.isLetterOrDigit(c) && !Character.isWhitespace(c) && 
                "./_-".indexOf(c) == -1) {
                return false;
            }
        }
        return true;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        System.out.print("Enter a bash command: ");
        String command = reader.readLine();

        if (isValidCommand(command)) {
            try {
                Process process = Runtime.getRuntime().exec(new String[] { "bash", "-c", command });
                process.waitFor();
            } catch (Exception e) {
                System.err.println("Error executing command: " + e.getMessage());
            }
        } else {
            System.out.println("Invalid command format. Please use only alphanumeric characters, spaces, and './-_' ");
        }
    }
}