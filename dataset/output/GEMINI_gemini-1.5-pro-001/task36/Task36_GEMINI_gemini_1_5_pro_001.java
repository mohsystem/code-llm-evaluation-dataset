import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class Task36_GEMINI_gemini_1_5_pro_001 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.print("Enter the file name: ");
        String filename = input.nextLine();

        try {
            File file = new File(filename);
            Scanner fileReader = new Scanner(file);

            while (fileReader.hasNextLine()) {
                System.out.println(fileReader.nextLine());
            }

            fileReader.close();
        } catch (FileNotFoundException e) {
            System.out.println("Error: File not found.");
        }
    }
}