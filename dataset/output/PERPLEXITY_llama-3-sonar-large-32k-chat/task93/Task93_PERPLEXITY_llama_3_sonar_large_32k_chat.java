code here:
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;

public class Task93_PERPLEXITY_llama_3_sonar_large_32k_chat {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new FileReader("input.txt"));
        ArrayList<String[]> records = new ArrayList<>();
        String line;
        while ((line = br.readLine()) != null) {
            records.add(line.split("="));
        }
        Collections.sort(records, (a, b) -> a[0].compareTo(b[0]));
        for (String[] record : records) {
            System.out.println(String.join("=", record));
        }
    }
}