
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

public class Task119_CLAUDE_claude_3_5_sonnet_20240620 {
    public static void processCSV(String filePath) {
        try (BufferedReader br = new BufferedReader(new FileReader(filePath))) {
            String line;
            String[] header = br.readLine().split(",");
            System.out.println("CSV Header: " + String.join(", ", header));

            while ((line = br.readLine()) != null) {
                String[] row = line.split(",");
                System.out.println("Row: " + String.join(", ", row));
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public static void main(String[] args) {
        String filePath = "example.csv";
        processCSV(filePath);
    }
}
