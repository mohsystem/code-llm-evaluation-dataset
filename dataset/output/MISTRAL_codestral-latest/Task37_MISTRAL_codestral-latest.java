// Java
import java.sql.*;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter username: ");
        String username = scanner.nextLine();

        String url = "jdbc:mysql://localhost:3306/myDatabase";
        String dbUsername = "username";
        String password = "password";

        try {
            Connection conn = DriverManager.getConnection(url, dbUsername, password);
            Statement stmt = conn.createStatement();
            String sql = "SELECT * FROM Users WHERE username = '" + username + "'";
            ResultSet rs = stmt.executeQuery(sql);

            while(rs.next()) {
                System.out.println(rs.getString("username") + " " + rs.getString("email"));
            }
            conn.close();
        } catch (Exception e) {
            System.out.println(e);
        }
    }
}