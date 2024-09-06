import java.util.Scanner;

public class Task118_PERPLEXITY_llama_3_sonar_large_32k_chat {
    public static boolean validateIP(String ip) {
        String[] parts = ip.split("\\.");
        if (parts.length != 4) {
            return false;
        }
        for (String part : parts) {
            if (!part.matches("\\d+")) {
                return false;
            }
            int num = Integer.parseInt(part);
            if (num > 255 || num < 0) {
                return false;
            }
        }
        return true;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter an IP address: ");
        String ip = scanner.nextLine();
        if (validateIP(ip)) {
            System.out.println("IP address is valid");
        } else {
            System.out.println("IP address is not valid");
        }
    }
}