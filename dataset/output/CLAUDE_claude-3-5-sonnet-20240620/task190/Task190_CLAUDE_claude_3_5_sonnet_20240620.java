
import java.io.*;
import java.util.*;

public class Task190_CLAUDE_claude_3_5_sonnet_20240620 {
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new FileReader("file.txt"));
        List<String[]> lines = new ArrayList<>();
        String line;
        
        while ((line = reader.readLine()) != null) {
            lines.add(line.split(" "));
        }
        reader.close();
        
        int rowCount = lines.size();
        int colCount = lines.get(0).length;
        
        for (int j = 0; j < colCount; j++) {
            for (int i = 0; i < rowCount; i++) {
                System.out.print(lines.get(i)[j]);
                if (i < rowCount - 1) System.out.print(" ");
            }
            System.out.println();
        }
    }
}
