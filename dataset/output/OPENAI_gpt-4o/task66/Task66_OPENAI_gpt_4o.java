import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Task66_OPENAI_gpt_4o {
    public static void main(String[] args) {
        try {
            BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
            System.out.print("Enter a bash command: ");
            String command = reader.readLine();
            
            Process process = Runtime.getRuntime().exec(command);
            BufferedReader stdInput = new BufferedReader(new InputStreamReader(process.getInputStream()));
            BufferedReader stdError = new BufferedReader(new InputStreamReader(process.getErrorStream()));
            
            String s;
            System.out.println("Command output:");
            while ((s = stdInput.readLine()) != null) {
                System.out.println(s);
            }
            
            while ((s = stdError.readLine()) != null) {
                System.out.println("Error: " + s);
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}