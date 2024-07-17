import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;

public class Main {
    public static void main(String[] args) {
        Connection connection = createConnection();
    }

    public static Connection createConnection() {
        Connection connection = null;
        String url = "jdbc:postgresql://localhost:5432/mydatabase";
        String user = "myuser";
        String password = "mypassword";
        try {
            connection = DriverManager.getConnection(url, user, password);
            System.out.println("Java: Connection established successfully.");
        } catch (SQLException e) {
            System.out.println("Java: Connection failed.");
            e.printStackTrace();
        }
        return connection;
    }
}