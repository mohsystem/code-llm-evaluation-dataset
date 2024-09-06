import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

public class Task65_PERPLEXITY_llama_3_sonar_large_32k_chat {
    public static void main(String[] args) {
        if (args.length != 1) {
            System.out.println("Usage: java Task65_PERPLEXITY_llama_3_sonar_large_32k_chat <filename>");
            return;
        }
        String filename = args[0];
        try (BufferedReader br = new BufferedReader(new FileReader(filename))) {
            String line;
            while ((line = br.readLine()) != null) {
                System.out.println(line);
            }
        } catch (IOException e) {
            System.err.println("Error: An error occurred while reading file '" + filename + "': " + e.getMessage());
        }
    }
}