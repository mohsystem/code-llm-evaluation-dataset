import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new FileReader("file.txt"));
        String line;
        String[] lines = new String[0];
        while ((line = br.readLine()) != null) {
            String[] temp = lines;
            lines = new String[temp.length + 1];
            System.arraycopy(temp, 0, lines, 0, temp.length);
            lines[lines.length - 1] = line;
        }
        br.close();
        String[] cols = lines[0].split(" ");
        for (int i = 0; i < cols.length; i++) {
            for (int j = 0; j < lines.length; j++) {
                System.out.print(lines[j].split(" ")[i] + " ");
            }
            System.out.println();
        }
    }
}