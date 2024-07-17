import java.io.*;
import java.util.*;

public class RecordSorter {
    public static void main(String[] args) {
        List<String> records = new ArrayList<>();
        try (BufferedReader br = new BufferedReader(new FileReader("data.txt"))) {
            String line;
            while ((line = br.readLine()) != null) {
                records.add(line);
            }
        } catch (IOException e) {
            e.printStackTrace();
        }

        Collections.sort(records);

        try (BufferedWriter bw = new BufferedWriter(new FileWriter("sorted_data.txt"))) {
            for (String record : records) {
                bw.write(record);
                bw.newLine();
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}