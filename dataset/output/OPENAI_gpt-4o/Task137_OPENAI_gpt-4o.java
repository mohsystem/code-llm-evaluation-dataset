import java.sql.*;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        try (Connection conn = DriverManager.getConnection("jdbc:sqlite::memory:");
             Statement stmt = conn.createStatement()) {

            stmt.execute("CREATE TABLE product (id INTEGER PRIMARY KEY, name TEXT, price REAL)");
            stmt.execute("INSERT INTO product (name, price) VALUES ('Apple', 1.0)");
            stmt.execute("INSERT INTO product (name, price) VALUES ('Banana', 0.5)");
            stmt.execute("INSERT INTO product (name, price) VALUES ('Cherry', 2.0)");

            Scanner scanner = new Scanner(System.in);
            System.out.println("Enter product name: ");
            String productName = scanner.nextLine();

            PreparedStatement pstmt = conn.prepareStatement("SELECT * FROM product WHERE name=?");
            pstmt.setString(1, productName);

            ResultSet rs = pstmt.executeQuery();
            if (rs.next()) {
                System.out.println("Product ID: " + rs.getInt("id") + ", Name: " + rs.getString("name") + ", Price: " + rs.getDouble("price"));
            } else {
                System.out.println("Product not found.");
            }
        } catch (SQLException e) {
            System.out.println(e.getMessage());
        }
    }
}