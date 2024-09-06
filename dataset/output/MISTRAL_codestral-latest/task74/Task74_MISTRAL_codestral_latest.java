// Java
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;

public class Task74_MISTRAL_codestral_latest {
    public static Connection createDBConnection() {
        Connection connection = null;
        try {
            connection = DriverManager.getConnection(
                    "jdbc:postgresql://localhost:5432/your_database",
                    "your_username", "your_password");
        } catch (SQLException e) {
            System.out.println("Error while connecting to PostgreSQL");
            e.printStackTrace();
        }
        return connection;
    }

    public static void main(String[] args) {
        Connection conn = createDBConnection();
    }
}