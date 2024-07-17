import javax.xml.xpath.*;
import org.w3c.dom.*;
import javax.xml.parsers.*;
import java.io.*;
import org.xml.sax.InputSource;

public class ProcessXML {

    public static void main(String[] args) throws Exception {
        if (args.length != 2) {
            System.out.println("Usage: <program> <xpath> <xmlfile>");
            return;
        }

        String xpathExpr = args[0];
        String xmlFile = args[1];

        File file = new File(xmlFile);
        DocumentBuilderFactory factory = DocumentBuilderFactory.newInstance();
        DocumentBuilder builder = factory.newDocumentBuilder();
        Document doc = builder.parse(file);

        XPathFactory xPathfactory = XPathFactory.newInstance();
        XPath xpath = xPathfactory.newXPath();
        XPathExpression expr = xpath.compile(xpathExpr);

        NodeList nl = (NodeList) expr.evaluate(doc, XPathConstants.NODESET);
        for (int i = 0; i < nl.getLength(); i++) {
            System.out.println(nl.item(i).getTextContent());
        }
    }
}