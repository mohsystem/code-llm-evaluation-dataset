
import java.io.*;
import java.util.*;

public class CSVProcessor {
    public static void main(String[] args) {
        String fileName = "data.csv";
        List<List<String>> data = new ArrayList<>();

        try (BufferedReader br = new BufferedReader(new FileReader(fileName))) {
            String line;
            while ((line = br.readLine()) != null) {
                String[] values = line.split(",");
                data.add(Arrays.asList(values));
            }
        } catch (IOException e) {
            e.printStackTrace();
            return;
        }

        for (List<String> row : data) {
            for (String value : row) {
                System.out.print(value + "\\t");
            }
            System.out.println();
        }
    }
}
