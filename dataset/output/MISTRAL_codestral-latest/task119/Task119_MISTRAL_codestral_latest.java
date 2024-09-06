import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

public class Task119_MISTRAL_codestral_latest {
    public static void main(String[] args) {
        String line = "";
        String splitBy = ",";

        try (BufferedReader br = new BufferedReader(new FileReader("your_file.csv"))) {
            while ((line = br.readLine()) != null) {
                String[] data = line.split(splitBy);
                for (String str : data) {
                    System.out.print(str + " ");
                }
                System.out.println();
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}