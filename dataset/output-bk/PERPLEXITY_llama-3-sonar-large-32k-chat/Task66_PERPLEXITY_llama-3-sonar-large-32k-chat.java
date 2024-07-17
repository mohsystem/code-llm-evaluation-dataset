import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;

public class Main {
    public static void main(String[] args) {
        try {
            Process process = Runtime.getRuntime().exec(getCommandFromUser());
            printOutput(process);
        } catch (IOException e) {
            System.err.println("Error executing command: " + e.getMessage());
        }
    }

    private static String getCommandFromUser() {
        try (BufferedReader reader = new BufferedReader(new InputStreamReader(System.in))) {
            System.out.print("Enter a bash command: ");
            return reader.readLine();
        } catch (IOException e) {
            System.err.println("Error reading input: " + e.getMessage());
            return "";
        }
    }

    private static void printOutput(Process process) throws IOException {
        try (BufferedReader output = new BufferedReader(new InputStreamReader(process.getInputStream()));
             BufferedReader error = new BufferedReader(new InputStreamReader(process.getErrorStream()))) {
            System.out.println("Output:");
            String line;
            while ((line = output.readLine()) != null) {
                System.out.println(line);
            }
            System.out.println("Error:");
            while ((line = error.readLine()) != null) {
                System.out.println(line);
            }
        }
    }
}