
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.regex.Pattern;

public class CommandExecutor {
    public static void main(String[] args) {
        try {
            BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
            System.out.print("Enter a bash command: ");
            String command = reader.readLine();

            if (validateCommand(command)) {
                Process process = Runtime.getRuntime().exec(new String[]{"bash", "-c", command});
                BufferedReader processOutput = new BufferedReader(new InputStreamReader(process.getInputStream()));
                String line;
                while ((line = processOutput.readLine()) != null) {
                    System.out.println(line);
                }
                process.waitFor();
            } else {
                System.out.println("Invalid command format or content.");
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    private static boolean validateCommand(String command) {
        // Basic validation: non-empty, no semicolons, pipes, or redirections
        return !command.isEmpty() && !Pattern.compile("[;|><]").matcher(command).find();
    }
}
