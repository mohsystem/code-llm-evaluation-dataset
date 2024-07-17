import java.io.*;
import java.util.*;

public class TransposeFile {
    public static void main(String[] args) throws IOException {
        List<String[]> lines = new ArrayList<>();
        BufferedReader reader = new BufferedReader(new FileReader("file.txt"));
        String line;
        while ((line = reader.readLine()) != null) {
            lines.add(line.split(" "));
        }
        reader.close();
        
        int columns = lines.get(0).length;
        for (int i = 0; i < columns; i++) {
            for (String[] row : lines) {
                System.out.print(row[i] + " ");
            }
            System.out.println();
        }
    }
}