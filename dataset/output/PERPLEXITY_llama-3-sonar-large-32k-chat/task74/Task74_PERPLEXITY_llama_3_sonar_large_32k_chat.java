import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;

public class Task74_PERPLEXITY_llama_3_sonar_large_32k_chat {
    public static Connection createConnection() {
        Connection conn = null;
        try {
            Class.forName("org.postgresql.Driver");
            conn = DriverManager.getConnection(
                "jdbc:postgresql://localhost:5432/database_name",
                "username",
                "password"
            );
            return conn;
        } catch (ClassNotFoundException e) {
            System.out.println("PostgreSQL JDBC driver not found.");
        } catch (SQLException e) {
            System.out.println("Error connecting to database.");
        }
        return conn;
    }

    public static void main(String[] args) {
        Connection conn = createConnection();
        if (conn != null) {
            try {
                conn.close();
            } catch (SQLException e) {
                System.out.println("Error closing connection.");
            }
        }
    }
}