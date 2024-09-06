import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Task104_GEMINI_gemini_1_5_pro_001 {

    private static final int BUFFER_SIZE = 1024;

    public static void main(String[] args) {
        try (BufferedReader reader = new BufferedReader(new InputStreamReader(System.in))) {
            char[] buffer = new char[BUFFER_SIZE];
            System.out.println("Enter your input (max " + BUFFER_SIZE + " characters):");
            int charsRead = reader.read(buffer, 0, BUFFER_SIZE);
            if (charsRead != -1) {
                String inputData = new String(buffer, 0, charsRead);
                System.out.println("\nYou entered:\n" + inputData);
            }
        } catch (IOException e) {
            System.err.println("Error reading input: " + e.getMessage());
        }
    }
}