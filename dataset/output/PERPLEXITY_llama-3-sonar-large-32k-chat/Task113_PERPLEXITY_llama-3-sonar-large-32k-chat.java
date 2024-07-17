import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter the number of strings:");
        int n = scanner.nextInt();
        String result = "";
        for (int i = 0; i < n; i++) {
            System.out.println("Enter string " + (i + 1) + ":");
            result += scanner.next();
        }
        System.out.println("Concatenated string: " + result);
    }
}