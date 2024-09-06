import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class Task119_OPENAI_gpt_4o {
    
    public static void readCSV(String filePath) {
        String line = "";
        String splitBy = ",";
        try (BufferedReader br = new BufferedReader(new FileReader(filePath))) {
            while ((line = br.readLine()) != null) {
                String[] row = line.split(splitBy);
                for(String data : row){
                    System.out.print(data + " ");
                }
                System.out.println();
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public static void writeCSV(String filePath, String[][] data) {
        try (FileWriter writer = new FileWriter(filePath)) {
            for (String[] row : data) {
                writer.append(String.join(",", row));
                writer.append("\n");
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public static void main(String[] args) {
        String[][] data = {
                {"Name", "Age", "City"},
                {"Alice", "30", "New York"},
                {"Bob", "25", "Los Angeles"},
                {"Charlie", "35", "Chicago"}
        };

        String filePath = "example.csv";

        writeCSV(filePath, data);
        readCSV(filePath);
    }
}