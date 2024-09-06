// Java

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class Task93_MISTRAL_codestral_latest {
    public static void main(String[] args) {
        List<String> records = readAndSortFile("path_to_your_file.txt");
        for (String record : records) {
            System.out.println(record);
        }
    }

    private static List<String> readAndSortFile(String filePath) {
        List<String> records = new ArrayList<>();
        try (BufferedReader br = new BufferedReader(new FileReader(filePath))) {
            String line;
            while ((line = br.readLine()) != null) {
                records.add(line);
            }
            Collections.sort(records);
        } catch (IOException e) {
            e.printStackTrace();
        }
        return records;
    }
}