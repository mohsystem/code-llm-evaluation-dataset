import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

public class Task190_GEMINI_gemini_1_5_pro_001 {
    public static void main(String[] args) throws IOException {
        List<List<String>> matrix = new ArrayList<>();
        BufferedReader reader = new BufferedReader(new FileReader("file.txt"));
        String line;

        // Read file into a list of lists (matrix)
        while ((line = reader.readLine()) != null) {
            String[] parts = line.split(" ");
            List<String> row = new ArrayList<>();
            for (String part : parts) {
                row.add(part);
            }
            matrix.add(row);
        }
        reader.close();

        // Transpose the matrix
        for (int i = 0; i < matrix.get(0).size(); i++) {
            for (int j = 0; j < matrix.size(); j++) {
                System.out.print(matrix.get(j).get(i) + " ");
            }
            System.out.println();
        }
    }
}