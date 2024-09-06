import java.sql.*;

public class Task67_MISTRAL_codestral_latest {
    private static final String DB_URL = "jdbc:sqlite:database.db";

    public static void main(String[] args) {
        if (args.length != 1) {
            System.out.println("Usage: java Task67_MISTRAL_codestral_latest <customerusername>");
            System.exit(1);
        }

        String customerUsername = args[0];
        try (Connection conn = DriverManager.getConnection(DB_URL);
             PreparedStatement pstmt = conn.prepareStatement("SELECT * FROM customer WHERE customerusername = ?")) {

            pstmt.setString(1, customerUsername);
            ResultSet rs = pstmt.executeQuery();

            if (rs.next()) {
                System.out.println("Customer Info: " + rs.getString("customerusername") + ", " + rs.getString("other_column"));
            } else {
                System.out.println("No customer found with username: " + customerUsername);
            }
        } catch (SQLException e) {
            System.err.println(e.getMessage());
        }
    }
}