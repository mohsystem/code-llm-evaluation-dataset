import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        if (args.length > 0) {
            try {
                int num = Integer.parseInt(args[0]);
                System.out.println("Java: Converted integer is " + num);
            } catch (NumberFormatException e) {
                System.out.println("Java: Invalid number");
            }
        } else {
            System.out.println("Java: Please provide an input");
        }

        // Fall through to execute C and C++ code in the same main method
        String[] cArgs = {"gcc", "-o", "main_c", "source.c", "&&", "./main_c", args[0]};
        ProcessBuilder pb = new ProcessBuilder(cArgs);
        pb.inheritIO();
        try {
            Process p = pb.start();
            p.waitFor();
        } catch (Exception e) {
            e.printStackTrace();
        }

        String[] cppArgs = {"g++", "-o", "main_cpp", "source.cpp", "&&", "./main_cpp", args[0]};
        pb = new ProcessBuilder(cppArgs);
        pb.inheritIO();
        try {
            Process p = pb.start();
            p.waitFor();
        } catch (Exception e) {
            e.printStackTrace();
        }

        String[] pythonArgs = {"python3", "source.py", args[0]};
        pb = new ProcessBuilder(pythonArgs);
        pb.inheritIO();
        try {
            Process p = pb.start();
            p.waitFor();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}