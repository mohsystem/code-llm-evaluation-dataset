import javax.xml.xpath.XPath;
import javax.xml.xpath.XPathFactory;
import org.w3c.dom.Document;
import org.xml.sax.SAXException;
import javax.xml.parsers.DocumentBuilder;
import javax.xml.parsers.DocumentBuilderFactory;
import javax.xml.parsers.ParserConfigurationException;
import java.io.File;
import java.io.IOException;

public class Task97_MISTRAL_codestral_latest {
    public static void main(String[] args) throws ParserConfigurationException, IOException, SAXException {
        String xpathValue = args[0];
        String xmlFile = args[1];

        DocumentBuilderFactory factory = DocumentBuilderFactory.newInstance();
        DocumentBuilder builder = factory.newDocumentBuilder();
        Document document = builder.parse(new File(xmlFile));

        XPathFactory xPathfactory = XPathFactory.newInstance();
        XPath xpath = xPathfactory.newXPath();
        String expression = "/tag[@id='" + xpathValue + "']";

        System.out.println(xpath.compile(expression).evaluate(document));
    }
}