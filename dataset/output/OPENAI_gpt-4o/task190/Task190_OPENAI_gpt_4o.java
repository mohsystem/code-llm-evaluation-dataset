import java.io.*;
import java.util.*;

public class Task190_OPENAI_gpt_4o {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new FileReader("file.txt"));
        List<String[]> lines = new ArrayList<>();
        String line;
        while ((line = br.readLine()) != null) {
            lines.add(line.split(" "));
        }
        br.close();
        
        int numCols = lines.get(0).length;
        for (int i = 0; i < numCols; i++) {
            for (int j = 0; j < lines.size(); j++) {
                System.out.print(lines.get(j)[i]);
                if (j < lines.size() - 1) System.out.print(" ");
            }
            System.out.println();
        }
    }
}