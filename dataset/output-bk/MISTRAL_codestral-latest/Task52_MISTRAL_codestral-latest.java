// Java
import java.io.*;
import java.util.Scanner;

public class CaesarCipher {
    public static void main(String[] args) throws IOException {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter the shift value: ");
        int shift = scanner.nextInt();
        System.out.println("Enter the input file path: ");
        String inputFile = scanner.next();
        System.out.println("Enter the output file path: ");
        String outputFile = scanner.next();
        caesarCipher(shift, inputFile, outputFile);
    }

    public static void caesarCipher(int shift, String inputFile, String outputFile) throws IOException {
        FileReader reader = new FileReader(inputFile);
        FileWriter writer = new FileWriter(outputFile);
        int character;
        while ((character = reader.read()) != -1) {
            if (Character.isLetter(character)) {
                if (Character.isLowerCase(character)) {
                    character = (character - 'a' + shift) % 26 + 'a';
                } else {
                    character = (character - 'A' + shift) % 26 + 'A';
                }
            }
            writer.write(character);
        }
        reader.close();
        writer.close();
    }
}