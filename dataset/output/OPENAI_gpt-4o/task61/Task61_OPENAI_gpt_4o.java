import javax.xml.parsers.DocumentBuilderFactory;
import javax.xml.parsers.DocumentBuilder;
import org.w3c.dom.Document;
import java.io.ByteArrayInputStream;

public class Task61_OPENAI_gpt_4o {
    public static void main(String[] args) {
        try {
            String xmlString = "<?xml version=\"1.0\"?><root><child1>Content1</child1><child2><subchild1>Content2</subchild1></child2></root>";
            DocumentBuilderFactory factory = DocumentBuilderFactory.newInstance();
            DocumentBuilder builder = factory.newDocumentBuilder();
            Document doc = builder.parse(new ByteArrayInputStream(xmlString.getBytes()));
            String rootElement = doc.getDocumentElement().getTagName();
            System.out.println(rootElement);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}