import javax.xml.xpath.XPath;
import javax.xml.xpath.XPathConstants;
import javax.xml.xpath.XPathExpression;
import javax.xml.xpath.XPathFactory;

import org.w3c.dom.Document;
import org.w3c.dom.NodeList;
import org.xml.sax.SAXException;

import java.io.File;
import java.io.IOException;

public class Task97_PERPLEXITY_llama_3_sonar_large_32k_chat {
    public static void main(String[] args) throws Exception {
        String xpathValue = args[0];
        String xmlFileName = args[1];

        XPathFactory xPathFactory = XPathFactory.newInstance();
        XPath xpath = xPathFactory.newXPath();

        Document doc = javax.xml.parsers.DocumentBuilderFactory.newInstance()
                .newDocumentBuilder()
                .parse(new File(xmlFileName));

        XPathExpression expr = xpath.compile("/tag[@id={" + xpathValue + "}]");
        NodeList result = (NodeList) expr.evaluate(doc, XPathConstants.NODESET);

        for (int i = 0; i < result.getLength(); i++) {
            System.out.println(result.item(i).getTextContent());
        }
    }
}