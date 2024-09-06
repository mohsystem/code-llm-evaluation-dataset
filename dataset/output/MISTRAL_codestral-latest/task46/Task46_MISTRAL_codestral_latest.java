// Java code using SQLite JDBC
import java.sql.*;

public class Task46_MISTRAL_codestral_latest {
    private Connection connect() {
        // SQLite connection string
        String url = "jdbc:sqlite:user_database.db";
        Connection conn = null;
        try {
            conn = DriverManager.getConnection(url);
        } catch (SQLException e) {
            System.out.println(e.getMessage());
        }
        return conn;
    }

    public void registerUser(String name, String email, String password) {
        String sql = "INSERT INTO users(name, email, password) VALUES(?,?,?)";

        try (Connection conn = this.connect();
                PreparedStatement pstmt = conn.prepareStatement(sql)) {
            pstmt.setString(1, name);
            pstmt.setString(2, email);
            pstmt.setString(3, password);
            pstmt.executeUpdate();
        } catch (SQLException e) {
            System.out.println(e.getMessage());
        }
    }

    public static void main(String[] args) {
        Task46_MISTRAL_codestral_latest app = new Task46_MISTRAL_codestral_latest();
        app.registerUser("John Doe", "johndoe@example.com", "password123");
    }
}