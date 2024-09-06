import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Task158_OPENAI_gpt_4o {
    public static void main(String[] args) {
        try {
            BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
            System.out.print("Enter the command to execute: ");
            String command = reader.readLine();
            Process process = Runtime.getRuntime().exec(command);
            process.waitFor();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}