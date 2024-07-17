
import org.apache.xmlrpc.server.XmlRpcServer;
import org.apache.xmlrpc.server.PropertyHandlerMapping;
import org.apache.xmlrpc.webserver.WebServer;
import org.apache.xmlrpc.XmlRpcException;

public class XMLRPCServer {
    public int add(int x, int y) {
        return x + y;
    }

    public static void main(String[] args) {
        try {
            WebServer webServer = new WebServer(8080);
            XmlRpcServer xmlRpcServer = webServer.getXmlRpcServer();

            PropertyHandlerMapping phm = new PropertyHandlerMapping();
            phm.addHandler("Calculator", XMLRPCServer.class);
            xmlRpcServer.setHandlerMapping(phm);

            webServer.start();
            System.out.println("XML-RPC Server is running on port 8080");
        } catch (Exception e) {
            System.err.println("XML-RPC Server: " + e);
        }
    }
}
