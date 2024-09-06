/* Simulated C++ part in Java (in CppPart.java) */

import java.util.Scanner;

class CPart {
    public static void main(String[] args) {
        System.out.println("Enter a string (C): ");
        Scanner scanner = new Scanner(System.in);
        String inputC = scanner.nextLine();
        System.out.println("You entered (C): " + inputC);
    }
}