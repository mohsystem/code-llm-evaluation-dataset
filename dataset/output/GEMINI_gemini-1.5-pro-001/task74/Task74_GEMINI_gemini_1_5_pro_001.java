import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;

public class Task74_GEMINI_gemini_1_5_pro_001 {

    public static Connection connectToPostgres(String host, String database, String user, String password) {
        Connection conn = null;
        try {
            Class.forName("org.postgresql.Driver");
            String url = "jdbc:postgresql://" + host + "/" + database;
            conn = DriverManager.getConnection(url, user, password);
            System.out.println("Connected to the PostgreSQL server successfully.");
        } catch (SQLException e) {
            System.out.println(e.getMessage());
        } catch (Exception e) {
            System.out.println("Error connecting to database: " + e.getMessage());
        }
        return conn;
    }
}