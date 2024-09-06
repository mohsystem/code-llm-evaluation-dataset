// Java
import java.io.File;
import java.io.IOException;
import java.io.RandomAccessFile;
import java.util.Scanner;

public class Task159_MISTRAL_codestral_latest {
    public static void main(String[] args) {
        try {
            // Allocate memory buffer
            try (RandomAccessFile raf = new RandomAccessFile("buffer.dat", "rw")) {
                raf.setLength(1024);  // 1KB buffer
            }

            // User input for index
            Scanner scanner = new Scanner(System.in);
            System.out.print("Enter index: ");
            int index = scanner.nextInt();
            scanner.close();

            // Read from buffer
            try (RandomAccessFile raf = new RandomAccessFile("buffer.dat", "r")) {
                raf.seek(index);
                byte value = raf.readByte();
                System.out.println("Value at index: " + value);
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}