import javax.xml.parsers.DocumentBuilderFactory;
import org.w3c.dom.Document;
import org.w3c.dom.Element;
import java.io.StringReader;

public class Main {
    public static void main(String[] args) throws Exception {
        String xmlString = "<root><child>Data</child></root>";
        Document doc = DocumentBuilderFactory.newInstance().newDocumentBuilder().parse(new InputSource(new StringReader(xmlString)));
        Element rootElement = doc.getDocumentElement();
        System.out.println("Root element: " + rootElement.getNodeName());
    }
}