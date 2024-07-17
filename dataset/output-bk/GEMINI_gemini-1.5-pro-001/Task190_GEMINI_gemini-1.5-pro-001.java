import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

public class TransposeFile {

    public static void main(String[] args) throws IOException {
        List<String[]> matrix = new ArrayList<>();
        BufferedReader reader = new BufferedReader(new FileReader("file.txt"));
        String line;
        while ((line = reader.readLine()) != null) {
            matrix.add(line.split(" "));
        }
        reader.close();

        for (int j = 0; j < matrix.get(0).length; j++) {
            for (int i = 0; i < matrix.size(); i++) {
                System.out.print(matrix.get(i)[j] + " ");
            }
            System.out.println();
        }
    }
}