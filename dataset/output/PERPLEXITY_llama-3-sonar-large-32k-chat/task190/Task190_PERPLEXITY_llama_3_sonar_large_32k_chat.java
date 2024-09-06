import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

public class Task190_PERPLEXITY_llama_3_sonar_large_32k_chat {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new FileReader("file.txt"));
        List<List<String>> lines = new ArrayList<>();
        String line;
        while ((line = br.readLine()) != null) {
            String[] fields = line.split(" ");
            List<String> row = new ArrayList<>();
            for (String field : fields) {
                row.add(field);
            }
            lines.add(row);
        }
        List<List<String>> transposed = new ArrayList<>();
        for (int i = 0; i < lines.get(0).size(); i++) {
            List<String> col = new ArrayList<>();
            for (List<String> row : lines) {
                col.add(row.get(i));
            }
            transposed.add(col);
        }
        for (List<String> row : transposed) {
            for (String field : row) {
                System.out.print(field + " ");
            }
            System.out.println();
        }
    }
}