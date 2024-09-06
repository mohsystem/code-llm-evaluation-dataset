import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;

public class Task127_MISTRAL_codestral_latest {
    public static void main(String[] args) {
        try {
            FileInputStream fis = new FileInputStream("source_file.txt");
            FileOutputStream fos = new FileOutputStream("destination_file.txt");

            int content;
            while ((content = fis.read()) != -1) {
                fos.write(content);
            }

            fis.close();
            fos.close();
        } catch (IOException e) {
            System.out.println("An error occurred: " + e.getMessage());
        }
    }
}