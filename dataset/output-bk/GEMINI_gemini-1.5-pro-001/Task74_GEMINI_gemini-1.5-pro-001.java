import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;

public class PostgreSQLConnection {

    public static void main(String[] args) {

        Connection connection = null;

        try {
            connection = getConnection();

            if (connection != null) {
                System.out.println("Connected to the PostgreSQL server successfully.");
            } else {
                System.out.println("Failed to make connection!");
            }

        } catch (SQLException e) {
            System.out.println("Connection failure.");
            e.printStackTrace();
        }

    }

    public static Connection getConnection() throws SQLException {
        String dbURL = "jdbc:postgresql://localhost:5432/your_database_name";
        String user = "your_username";
        String pass = "your_password";
        return DriverManager.getConnection(dbURL, user, pass);

    }
}