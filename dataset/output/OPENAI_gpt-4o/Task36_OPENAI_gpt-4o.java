import java.io.*;
import java.util.Scanner;

public class MultiLangFileReader {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter the file name:");
        String fileName = scanner.nextLine();

        try {
            BufferedReader br = new BufferedReader(new FileReader(fileName));
            String line;
            while ((line = br.readLine()) != null) {
                System.out.println(line);
            }
            br.close();
        } catch (IOException e) {
            System.out.println("An error occurred.");
            e.printStackTrace();
        }

        // Call C function
        readFileInC(fileName);

        // Call C++ function
        readFileInCpp(fileName);

        // Call Python function
        readFileInPython(fileName);
    }

    public static native void readFileInC(String fileName);
    public static native void readFileInCpp(String fileName);
    public static native void readFileInPython(String fileName);

    static {
        System.loadLibrary("MultiLangFileReader");
    }
}