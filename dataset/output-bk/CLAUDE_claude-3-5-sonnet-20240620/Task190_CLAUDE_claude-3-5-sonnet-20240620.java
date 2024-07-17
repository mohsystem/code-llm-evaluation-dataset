
import java.io.*;
import java.util.*;

public class TransposeFile {
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new FileReader("file.txt"));
        List<String[]> lines = new ArrayList<>();
        String line;
        while ((line = reader.readLine()) != null) {
            lines.add(line.split(" "));
        }
        reader.close();

        int rows = lines.size();
        int cols = lines.get(0).length;

        for (int j = 0; j < cols; j++) {
            for (int i = 0; i < rows; i++) {
                System.out.print(lines.get(i)[j]);
                if (i < rows - 1) System.out.print(" ");
            }
            System.out.println();
        }
    }
}
