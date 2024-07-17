import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

public class ShellCommandExecutor {
    public static void main(String[] args) {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        String command = "";

        try {
            System.out.println("Enter a shell command:");
            command = reader.readLine();
            Process process = Runtime.getRuntime().exec(command);
            BufferedReader processReader = new BufferedReader(new InputStreamReader(process.getInputStream()));
            String line;
            while ((line = processReader.readLine()) != null) {
                System.out.println(line);
            }
        } catch (IOException e) {
            System.err.println("Error executing command: " + e.getMessage());
        }
    }
}