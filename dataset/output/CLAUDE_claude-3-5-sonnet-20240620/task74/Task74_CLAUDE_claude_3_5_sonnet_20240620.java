
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;

public class Task74_CLAUDE_claude_3_5_sonnet_20240620 {
    public static Connection createConnection() {
        String url = "jdbc:postgresql://localhost:5432/your_database";
        String user = "your_username";
        String password = "your_password";

        try {
            Connection connection = DriverManager.getConnection(url, user, password);
            System.out.println("Connection created successfully");
            return connection;
        } catch (SQLException e) {
            System.out.println("Error while connecting to PostgreSQL: " + e.getMessage());
            return null;
        }
    }

    public static void main(String[] args) {
        Connection connection = createConnection();
        if (connection != null) {
            try {
                connection.close();
            } catch (SQLException e) {
                System.out.println("Error while closing connection: " + e.getMessage());
            }
        }
    }
}
