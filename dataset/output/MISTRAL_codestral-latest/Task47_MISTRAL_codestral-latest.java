// Java
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
        try {
            Document document = Jsoup.connect("http://example.com").get();
            Elements elements = document.select("div.content");
            Connection connection = DriverManager.getConnection("jdbc:mysql://localhost/test", "user", "password");
            for (Element element : elements) {
                String data = element.text();
                PreparedStatement statement = connection.prepareStatement("INSERT INTO table (column) VALUES (?)");
                statement.setString(1, data);
                statement.executeUpdate();
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}