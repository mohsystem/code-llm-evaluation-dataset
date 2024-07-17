
import org.jsoup.Jsoup;
import org.jsoup.nodes.Document;
import org.jsoup.nodes.Element;
import org.jsoup.select.Elements;
import java.sql.*;

public class WebScraper {
    public static void main(String[] args) {
        String url = "https://example.com";
        String dbUrl = "jdbc:sqlite:scraped_data.db";

        try {
            // Connect to the website
            Document doc = Jsoup.connect(url).get();

            // Connect to the database
            Connection conn = DriverManager.getConnection(dbUrl);
            Statement stmt = conn.createStatement();

            // Create table if not exists
            stmt.execute("CREATE TABLE IF NOT EXISTS scraped_data (id INTEGER PRIMARY KEY AUTOINCREMENT, title TEXT, content TEXT)");

            // Select all paragraph elements
            Elements paragraphs = doc.select("p");

            // Insert data into the database
            for (Element paragraph : paragraphs) {
                String title = paragraph.select("strong").text();
                String content = paragraph.text();

                PreparedStatement pstmt = conn.prepareStatement("INSERT INTO scraped_data (title, content) VALUES (?, ?)");
                pstmt.setString(1, title);
                pstmt.setString(2, content);
                pstmt.executeUpdate();
            }

            // Close connections
            stmt.close();
            conn.close();

            System.out.println("Data scraped and stored successfully.");
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
