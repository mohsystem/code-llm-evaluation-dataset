import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.Statement;
import java.sql.SQLException;
import java.util.Scanner;

public class Task46_OPENAI_gpt_4o {
    public static void main(String[] args) {
        try {
            createTable();
            Scanner scanner = new Scanner(System.in);
            System.out.print("Enter your name: ");
            String name = scanner.nextLine();
            System.out.print("Enter your email: ");
            String email = scanner.nextLine();
            System.out.print("Enter your password: ");
            String password = scanner.nextLine();
            registerUser(name, email, password);
            System.out.println("User registered successfully!");
            scanner.close();
        } catch (Exception e) {
            System.out.println("Error: " + e.getMessage());
        }
    }

    public static void createTable() throws SQLException {
        try (Connection conn = DriverManager.getConnection("jdbc:sqlite:users.db")) {
            Statement stmt = conn.createStatement();
            stmt.execute("CREATE TABLE IF NOT EXISTS users (id INTEGER PRIMARY KEY AUTOINCREMENT, name TEXT NOT NULL, email TEXT NOT NULL, password TEXT NOT NULL);");
        }
    }

    public static void registerUser(String name, String email, String password) throws SQLException {
        try (Connection conn = DriverManager.getConnection("jdbc:sqlite:users.db")) {
            Statement stmt = conn.createStatement();
            stmt.execute(String.format("INSERT INTO users (name, email, password) VALUES ('%s', '%s', '%s');", name, email, password));
        }
    }
}