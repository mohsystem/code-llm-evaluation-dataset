import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;

public class Task74_OPENAI_gpt_4o {
    public static Connection getPostgresConnection() {
        Connection connection = null;
        try {
            String url = "jdbc:postgresql://your_host:your_port/your_database";
            String user = "your_username";
            String password = "your_password";
            connection = DriverManager.getConnection(url, user, password);
        } catch (SQLException e) {
            System.out.println("Error while connecting to PostgreSQL: " + e.getMessage());
        }
        return connection;
    }

    public static void main(String[] args) {
        Connection connection = getPostgresConnection();
    }
}