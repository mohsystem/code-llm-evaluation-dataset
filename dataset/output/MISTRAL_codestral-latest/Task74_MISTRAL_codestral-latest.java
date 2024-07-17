// Java
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;

public class PostgresConnection {
    public static Connection getConnection() throws SQLException {
        String url = "jdbc:postgresql://localhost/test";
        String user = "postgres";
        String password = "password";
        return DriverManager.getConnection(url, user, password);
    }
}