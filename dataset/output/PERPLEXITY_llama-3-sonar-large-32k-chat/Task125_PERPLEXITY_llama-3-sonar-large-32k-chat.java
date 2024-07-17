import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter the resource you want to access: ");
        String resource = scanner.nextLine();
        accessResource(resource);
    }

    public static void accessResource(String resource) {
        if (resource.equals("admin")) {
            System.out.println("Access granted to admin resource");
        } else if (resource.equals("moderator")) {
            System.out.println("Access granted to moderator resource");
        } else if (resource.equals("user")) {
            System.out.println("Access granted to user resource");
        } else {
            System.out.println("Access denied");
        }
    }
}