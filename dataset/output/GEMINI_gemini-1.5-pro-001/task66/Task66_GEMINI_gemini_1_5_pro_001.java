import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Task66_GEMINI_gemini_1_5_pro_001 {

    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        System.out.print("Enter a bash command: ");
        String command = reader.readLine();

        try {
            Process process = Runtime.getRuntime().exec(new String[] {"bash", "-c", command});
            BufferedReader input = new BufferedReader(new InputStreamReader(process.getInputStream()));
            String line;
            while ((line = input.readLine()) != null) {
                System.out.println(line);
            }
            BufferedReader error = new BufferedReader(new InputStreamReader(process.getErrorStream()));
            while ((line = error.readLine()) != null) {
                System.err.println(line);
            }
        } catch (IOException e) {
            System.err.println("Error executing command: " + e.getMessage());
        }
    }
}