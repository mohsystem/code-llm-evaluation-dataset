// Java
import org.jsoup.Jsoup;
import org.jsoup.nodes.Document;
import org.jsoup.nodes.Element;
import org.jsoup.select.Elements;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;

public class Task47_MISTRAL_codestral_latest {
    public static void main(String[] args) {
        try {
            // Connect to SQLite database
            Connection conn = DriverManager.getConnection("jdbc:sqlite:website_data.db");

            // Create table
            String sql = "CREATE TABLE IF NOT EXISTS data (title TEXT, link TEXT)";
            PreparedStatement pstmt = conn.prepareStatement(sql);
            pstmt.executeUpdate();

            // Scrape data
            Document doc = Jsoup.connect("http://example.com").get();
            Elements items = doc.select("div.item");

            for (Element item : items) {
                String title = item.select("h2").text();
                String link = item.select("a").attr("href");

                // Insert data into table
                sql = "INSERT INTO data(title, link) VALUES(?, ?)";
                pstmt = conn.prepareStatement(sql);
                pstmt.setString(1, title);
                pstmt.setString(2, link);
                pstmt.executeUpdate();
            }

            // Close connection
            conn.close();
        } catch (Exception e) {
            System.err.println(e.getClass().getName() + ": " + e.getMessage());
            System.exit(0);
        }
    }
}