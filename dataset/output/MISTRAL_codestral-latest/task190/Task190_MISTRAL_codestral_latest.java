// Java
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.stream.Collectors;
import java.util.stream.IntStream;

public class Task190_MISTRAL_codestral_latest {
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new FileReader("file.txt"));
        List<String[]> lines = new ArrayList<>();
        String line;
        while ((line = reader.readLine()) != null) {
            lines.add(line.split(" "));
        }
        reader.close();

        List<String[]> transposed = IntStream.range(0, lines.get(0).length)
                .mapToObj(i -> lines.stream().map(row -> row[i]).toArray(String[]::new))
                .collect(Collectors.toList());

        for (String[] row : transposed) {
            System.out.println(String.join(" ", row));
        }
    }
}