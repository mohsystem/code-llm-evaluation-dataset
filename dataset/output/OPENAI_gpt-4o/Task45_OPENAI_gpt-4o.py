import java.util.Scanner;

public class MultiLangProgram {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter a number for Java: ");
        try {
            int javaNum = scanner.nextInt();
            System.out.println("Java read the number: " + javaNum);
        } catch (Exception e) {
            System.out.println("Invalid input in Java: " + e.getMessage());
        }
    }
}