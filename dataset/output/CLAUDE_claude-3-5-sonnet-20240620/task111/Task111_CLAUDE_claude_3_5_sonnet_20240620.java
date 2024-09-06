
import org.apache.xmlrpc.server.XmlRpcServer;
import org.apache.xmlrpc.server.XmlRpcServerConfigImpl;
import org.apache.xmlrpc.webserver.WebServer;

public class Task111_CLAUDE_claude_3_5_sonnet_20240620 {
    public int add(int x, int y) {
        return x + y;
    }

    public int subtract(int x, int y) {
        return x - y;
    }

    public static void main(String[] args) throws Exception {
        WebServer webServer = new WebServer(8000);
        XmlRpcServer xmlRpcServer = webServer.getXmlRpcServer();
        
        XmlRpcServerConfigImpl serverConfig = (XmlRpcServerConfigImpl) xmlRpcServer.getConfig();
        serverConfig.setEnabledForExtensions(true);
        
        xmlRpcServer.setHandlerMapping(new org.apache.xmlrpc.server.PropertyHandlerMapping());
        
        webServer.start();
        System.out.println("XML-RPC server is running on port 8000...");
    }
}
