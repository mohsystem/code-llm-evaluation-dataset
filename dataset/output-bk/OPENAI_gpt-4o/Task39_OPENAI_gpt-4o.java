import java.util.Scanner;

public class DisplayFileContents {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter the filename: ");
        String filename = sc.nextLine();

        try {
            Process p = Runtime.getRuntime().exec("cat " + filename);
            java.io.InputStream is = p.getInputStream();
            int c;
            while ((c = is.read()) != -1) {
                System.out.print((char) c);
            }
            is.close();
            p.waitFor();
        } catch (Exception e) {
            e.printStackTrace();
        } finally {
            sc.close();
        }
    }
}