
import java.sql.*;
import java.util.Scanner;

public class Task137_CLAUDE_claude_3_5_sonnet_20240620 {
    private static final String DB_URL = "jdbc:sqlite:products.db";

    public static void createTable() {
        try (Connection conn = DriverManager.getConnection(DB_URL);
             Statement stmt = conn.createStatement()) {
            String sql = "CREATE TABLE IF NOT EXISTS products " +
                         "(id INTEGER PRIMARY KEY AUTOINCREMENT, " +
                         " name TEXT, " +
                         " price REAL)";
            stmt.execute(sql);
        } catch (SQLException e) {
            System.out.println(e.getMessage());
        }
    }

    public static void addProduct(String name, double price) {
        String sql = "INSERT INTO products(name, price) VALUES(?,?)";
        try (Connection conn = DriverManager.getConnection(DB_URL);
             PreparedStatement pstmt = conn.prepareStatement(sql)) {
            pstmt.setString(1, name);
            pstmt.setDouble(2, price);
            pstmt.executeUpdate();
        } catch (SQLException e) {
            System.out.println(e.getMessage());
        }
    }

    public static void getProduct(int id) {
        String sql = "SELECT * FROM products WHERE id = ?";
        try (Connection conn = DriverManager.getConnection(DB_URL);
             PreparedStatement pstmt = conn.prepareStatement(sql)) {
            pstmt.setInt(1, id);
            ResultSet rs = pstmt.executeQuery();
            if (rs.next()) {
                System.out.printf("ID: %d, Name: %s, Price: $%.2f%n",
                                  rs.getInt("id"),
                                  rs.getString("name"),
                                  rs.getDouble("price"));
            } else {
                System.out.println("Product not found.");
            }
        } catch (SQLException e) {
            System.out.println(e.getMessage());
        }
    }

    public static void main(String[] args) {
        createTable();
        Scanner scanner = new Scanner(System.in);

        while (true) {
            System.out.println("\\n1. Add product");
            System.out.println("2. Get product details");
            System.out.println("3. Exit");
            System.out.print("Enter your choice: ");
            int choice = scanner.nextInt();
            scanner.nextLine(); // Consume newline

            switch (choice) {
                case 1:
                    System.out.print("Enter product name: ");
                    String name = scanner.nextLine();
                    System.out.print("Enter product price: ");
                    double price = scanner.nextDouble();
                    addProduct(name, price);
                    System.out.println("Product added successfully!");
                    break;
                case 2:
                    System.out.print("Enter product ID: ");
                    int id = scanner.nextInt();
                    getProduct(id);
                    break;
                case 3:
                    System.out.println("Exiting...");
                    System.exit(0);
                default:
                    System.out.println("Invalid choice. Please try again.");
            }
        }
    }
}
