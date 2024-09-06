import javax.xml.parsers.DocumentBuilder;
import javax.xml.parsers.DocumentBuilderFactory;
import javax.xml.xpath.XPath;
import javax.xml.xpath.XPathFactory;
import javax.xml.xpath.XPathExpression;
import javax.xml.xpath.XPathConstants;
import org.w3c.dom.Document;
import org.w3c.dom.Node;
import org.w3c.dom.Element;
import java.io.File;

public class Task97_OPENAI_gpt_4o {
    public static void main(String[] args) {
        if (args.length != 2) {
            System.out.println("Usage: java Task97_OPENAI_gpt_4o <xpath> <xmlfile>");
            return;
        }

        String xpathExpression = args[0];
        String xmlfile = args[1];
        
        try {
            DocumentBuilderFactory factory = DocumentBuilderFactory.newInstance();
            DocumentBuilder builder = factory.newDocumentBuilder();
            Document doc = builder.parse(new File(xmlfile));

            XPathFactory xPathfactory = XPathFactory.newInstance();
            XPath xpath = xPathfactory.newXPath();
            XPathExpression expr = xpath.compile(xpathExpression);
            Node result = (Node) expr.evaluate(doc, XPathConstants.NODE);
            
            if (result != null) {
                System.out.println(nodeToString(result));
            } else {
                System.out.println("No result found for the XPath query.");
            }
        } catch (Exception e) {
            System.out.println("Error: " + e.getMessage());
        }
    }

    private static String nodeToString(Node node) {
        StringBuilder sb = new StringBuilder();
        Element element = (Element) node;
        sb.append("<").append(element.getTagName());
        if (element.hasAttributes()) {
            for (int i = 0; i < element.getAttributes().getLength(); i++) {
                sb.append(" ").append(element.getAttributes().item(i).getNodeName())
                  .append("=\"").append(element.getAttributes().item(i).getNodeValue()).append("\"");
            }
        }
        sb.append(">");
        if (element.getTextContent() != null) {
            sb.append(element.getTextContent());
        }
        sb.append("</").append(element.getTagName()).append(">");
        return sb.toString();
    }
}