import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

public class Task119_GEMINI_gemini_1_5_pro_001 {

    public static void main(String[] args) {
        String csvFile = "data.csv";
        String line;
        String csvSplitBy = ",";

        try (BufferedReader br = new BufferedReader(new FileReader(csvFile))) {

            while ((line = br.readLine()) != null) {

                String[] data = line.split(csvSplitBy);
                System.out.println(String.join(", ", data));
            }

        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}