import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter a filename: ");
        String filename = scanner.nextLine();
        try {
            Process process = Runtime.getRuntime().exec("cat " + filename);
            process.waitFor();
        } catch (Exception e) {
            System.out.println("Error: " + e.getMessage());
        }
    }
}