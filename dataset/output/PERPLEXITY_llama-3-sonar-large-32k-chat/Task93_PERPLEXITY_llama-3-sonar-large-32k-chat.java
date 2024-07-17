import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;

public class Main {
    public static void main(String[] args) {
        try (BufferedReader br = new BufferedReader(new FileReader("input.txt"))) {
            List<String[]> records = new ArrayList<>();
            String line;
            while ((line = br.readLine()) != null) {
                String[] record = line.split("-");
                records.add(record);
            }
            Collections.sort(records, new Comparator<String[]>() {
                @Override
                public int compare(String[] o1, String[] o2) {
                    return o1[0].compareTo(o2[0]);
                }
            });
            for (String[] record : records) {
                System.out.println(record[0] + "-" + record[1]);
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}