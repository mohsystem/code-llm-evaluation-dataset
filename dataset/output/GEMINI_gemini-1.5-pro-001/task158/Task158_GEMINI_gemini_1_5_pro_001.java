import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Task158_GEMINI_gemini_1_5_pro_001 {
    public static void main(String[] args) {
        try {
            System.out.print("Enter OS command: ");
            BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
            String command = reader.readLine();
            Process process = Runtime.getRuntime().exec(command);
            BufferedReader errorReader = new BufferedReader(new InputStreamReader(process.getErrorStream()));
            String line;
            while ((line = errorReader.readLine()) != null) {
                System.err.println(line);
            }
            process.waitFor();
        } catch (IOException | InterruptedException e) {
            e.printStackTrace();
        }
    }
}