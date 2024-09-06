import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class Task65_MISTRAL_codestral_latest {
    public static void main(String[] args) {
        if (args.length != 1) {
            System.out.println("Usage: java Task65_MISTRAL_codestral_latest <filename>");
            return;
        }

        String filename = args[0];
        try {
            File file = new File(filename);
            Scanner scanner = new Scanner(file);
            while (scanner.hasNextLine()) {
                System.out.println(scanner.nextLine());
            }
            scanner.close();
        } catch (FileNotFoundException e) {
            System.out.println("Error: File not found.");
        }
    }
}