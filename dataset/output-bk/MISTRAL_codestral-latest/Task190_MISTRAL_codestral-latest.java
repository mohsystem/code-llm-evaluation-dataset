import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

public class TransposeFile {
    public static void main(String[] args) {
        List<String[]> lines = new ArrayList<>();
        try (BufferedReader br = new BufferedReader(new FileReader("file.txt"))) {
            String line;
            while ((line = br.readLine()) != null) {
                lines.add(line.split(" "));
            }
        } catch (IOException e) {
            e.printStackTrace();
        }

        for (int i = 0; i < lines.get(0).length; i++) {
            for (int j = 0; j < lines.size(); j++) {
                System.out.print(lines.get(j)[i] + " ");
            }
            System.out.println();
        }
    }
}