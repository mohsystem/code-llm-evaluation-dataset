import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.SQLException;
import java.util.Scanner;

public class Task46_PERPLEXITY_llama_3_sonar_large_32k_chat {
    private static final String DB_URL = "jdbc:sqlite:users.db";
    private static final String DRIVER = "org.sqlite.JDBC";

    public static void createTable() {
        try (Connection conn = DriverManager.getConnection(DB_URL);
             PreparedStatement pstmt = conn.prepareStatement("CREATE TABLE IF NOT EXISTS users (name TEXT, email TEXT PRIMARY KEY, password TEXT)")) {
            pstmt.executeUpdate();
        } catch (SQLException e) {
            System.out.println("Error creating table: " + e.getMessage());
        }
    }

    public static void registerUser(String name, String email, String password) {
        try (Connection conn = DriverManager.getConnection(DB_URL);
             PreparedStatement pstmt = conn.prepareStatement("INSERT INTO users VALUES (?, ?, ?)")) {
            pstmt.setString(1, name);
            pstmt.setString(2, email);
            pstmt.setString(3, password);
            pstmt.executeUpdate();
        } catch (SQLException e) {
            System.out.println("Error registering user: " + e.getMessage());
        }
    }

    public static void main(String[] args) {
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
    }
}