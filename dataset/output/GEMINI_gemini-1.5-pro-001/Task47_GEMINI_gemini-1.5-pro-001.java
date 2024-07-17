import org.jsoup.Jsoup;
import org.jsoup.nodes.Document;
import org.jsoup.nodes.Element;
import org.jsoup.select.Elements;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.SQLException;

public class WebScraper {
    public static void main(String[] args) {
        String url = "https://www.example.com/"; // Replace with the target website
        String dbUrl = "jdbc:sqlite:data.db"; // SQLite database file

        try {
            // Connect to the database (or create it if it doesn't exist)
            Connection conn = DriverManager.getConnection(dbUrl);
            // Create a table to store the data
            conn.createStatement().execute("CREATE TABLE IF NOT EXISTS website_data (title TEXT, link TEXT)");

            // Fetch the website content
            Document doc = Jsoup.connect(url).get();

            // Extract data (example: titles and links from 'a' tags)
            Elements links = doc.select("a[href]");
            for (Element link : links) {
                String title = link.text();
                String href = link.attr("abs:href");

                // Store the data in the database
                PreparedStatement pstmt = conn.prepareStatement("INSERT INTO website_data(title, link) VALUES(?, ?)");
                pstmt.setString(1, title);
                pstmt.setString(2, href);
                pstmt.executeUpdate();
            }

            // Close the database connection
            conn.close();

            System.out.println("Data scraped and stored successfully!");
        } catch (SQLException e) {
            System.err.println("Database error: " + e.getMessage());
        } catch (Exception e) {
            System.err.println("Error: " + e.getMessage());
        }
    }
}