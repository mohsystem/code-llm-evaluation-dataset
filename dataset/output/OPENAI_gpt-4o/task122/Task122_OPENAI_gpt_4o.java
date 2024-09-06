import java.util.ArrayList;
import java.util.Scanner;

class User {
    String username;
    String password;

    User(String username, String password) {
        this.username = username;
        this.password = password;
    }
}

public class Task122_OPENAI_gpt_4o {
    static ArrayList<User> database = new ArrayList<>();

    public static void signup(String username, String password) {
        database.add(new User(username, password));
        System.out.println("User signed up successfully");
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter username: ");
        String username = scanner.nextLine();
        System.out.print("Enter password: ");
        String password = scanner.nextLine();
        signup(username, password);
    }
}