import java.io.*;

public class Task70_PERPLEXITY_llama_3_sonar_large_32k_chat {
    public static void main(String[] args) {
        if (args.length != 1) {
            System.out.println("Usage: java Task70_PERPLEXITY_llama_3_sonar_large_32k_chat <file_path>");
            return;
        }
        try (BufferedReader br = new BufferedReader(new FileReader(args[0]))) {
            String line;
            while ((line = br.readLine()) != null) {
                System.out.println(line);
            }
        } catch (IOException e) {
            System.out.println("File not found");
        }
    }
}