import java.io.FileReader;
import java.io.BufferedReader;
import java.io.IOException;

public class Task119_PERPLEXITY_llama_3_sonar_large_32k_chat {
    public static void parseCSV(String fileName) {
        try (BufferedReader br = new BufferedReader(new FileReader(fileName))) {
            String line;
            while ((line = br.readLine()) != null) {
                String[] values = line.split(",");
                for (String value : values) {
                    System.out.print(value + " ");
                }
                System.out.println();
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public static void main(String[] args) {
        parseCSV("example.csv");
    }
}