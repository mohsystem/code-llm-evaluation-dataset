import java.util.Scanner;

public class Task39_OPENAI_gpt_4o {
    public static void main(String args[]) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter the filename: ");
        String filename = scanner.nextLine();
        String command = System.getProperty("os.name").startsWith("Windows") ? "type " : "cat ";
        try {
            Process process = Runtime.getRuntime().exec(command + filename);
            process.waitFor();
            java.io.InputStream is = process.getInputStream();
            int i;
            while ((i = is.read()) != -1) {
                System.out.print((char) i);
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}