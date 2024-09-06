// Java
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class Task94_MISTRAL_codestral_latest {
    public static void main(String[] args) {
        List<String> records = new ArrayList<>();
        try (BufferedReader br = new BufferedReader(new FileReader("file.txt"))) {
            String line;
            while ((line = br.readLine()) != null) {
                records.add(line);
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
        Collections.sort(records);
        for (String record : records) {
            System.out.println(record);
        }
    }
}