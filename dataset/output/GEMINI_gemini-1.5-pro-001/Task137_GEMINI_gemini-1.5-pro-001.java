import java.sql.*;
import java.util.Scanner;

public class ProductLookup {
    public static void main(String[] args) {
        Connection conn = null;
        Statement stmt = null;
        ResultSet rs = null;
        Scanner scanner = new Scanner(System.in);

        try {
            Class.forName("org.sqlite.JDBC");
            conn = DriverManager.getConnection("jdbc:sqlite:mydatabase.db");
            stmt = conn.createStatement();

            // Create the products table if it doesn't exist
            String createTableSql = "CREATE TABLE IF NOT EXISTS products (" +
                                   "id INTEGER PRIMARY KEY," +
                                   "name TEXT NOT NULL," +
                                   "description TEXT," +
                                   "price REAL)";
            stmt.executeUpdate(createTableSql);

            // Insert some sample data
            stmt.executeUpdate("INSERT INTO products (name, description, price) VALUES ('Apple', 'A sweet red fruit', 1.00)");
            stmt.executeUpdate("INSERT INTO products (name, description, price) VALUES ('Banana', 'A yellow curved fruit', 0.50)");
            stmt.executeUpdate("INSERT INTO products (name, description, price) VALUES ('Milk', 'A white dairy drink', 2.50)");

            while (true) {
                System.out.print("Enter a product name (or 'quit' to exit): ");
                String productName = scanner.nextLine();
                if (productName.equals("quit")) {
                    break;
                }

                String sql = "SELECT * FROM products WHERE name = '" + productName + "'";
                rs = stmt.executeQuery(sql);

                if (rs.next()) {
                    System.out.println("Product details:");
                    System.out.println("  ID: " + rs.getInt("id"));
                    System.out.println("  Name: " + rs.getString("name"));
                    System.out.println("  Description: " + rs.getString("description"));
                    System.out.println("  Price: " + rs.getDouble("price"));
                } else {
                    System.out.println("Product '" + productName + "' not found.");
                }
            }
        } catch (Exception e) {
            System.err.println(e.getMessage());
        } finally {
            try {
                if (rs != null) rs.close();
                if (stmt != null) stmt.close();
                if (conn != null) conn.close();
            } catch (SQLException e) {
                System.err.println(e.getMessage());
            }
        }
    }
}