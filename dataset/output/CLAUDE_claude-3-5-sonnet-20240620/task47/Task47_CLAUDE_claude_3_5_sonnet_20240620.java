
import org.jsoup.Jsoup;
import org.jsoup.nodes.Document;
import org.jsoup.select.Elements;
import java.io.IOException;
import java.sql.*;
import java.util.ArrayList;
import java.util.List;

public class Task47_CLAUDE_claude_3_5_sonnet_20240620 {
    public static List<String> scrapeWebsite(String url) throws IOException {
        Document doc = Jsoup.connect(url).get();
        Elements paragraphs = doc.select("p");
        List<String> data = new ArrayList<>();
        for (org.jsoup.nodes.Element paragraph : paragraphs) {
            data.add(paragraph.text());
        }
        return data;
    }

    public static void storeInDatabase(List<String> data) {
        String url = "jdbc:sqlite:scraped_data.db";
        try (Connection conn = DriverManager.getConnection(url)) {
            Statement stmt = conn.createStatement();
            stmt.execute("CREATE TABLE IF NOT EXISTS scraped_text (id INTEGER PRIMARY KEY, content TEXT)");
            
            String sql = "INSERT INTO scraped_text (content) VALUES (?)";
            PreparedStatement pstmt = conn.prepareStatement(sql);
            for (String item : data) {
                pstmt.setString(1, item);
                pstmt.executeUpdate();
            }
        } catch (SQLException e) {
            System.out.println(e.getMessage());
        }
    }

    public static void main(String[] args) {
        String url = "https://example.com"; // Replace with the website you want to scrape
        try {
            List<String> scrapedData = scrapeWebsite(url);
            storeInDatabase(scrapedData);
            System.out.println("Data scraped and stored successfully.");
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
