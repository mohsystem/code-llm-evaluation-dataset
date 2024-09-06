import java.util.Scanner;
public class Task39_GEMINI_gemini_1_5_pro_001 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.print("Enter the filename: ");
        String filename = input.nextLine();
        try {
            Process process = Runtime.getRuntime().exec("cat " + filename);
            process.waitFor();
        } catch (Exception e) {
            System.err.println("Error: " + e.getMessage());
        }
    }
}