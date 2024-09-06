// Java does not have built-in XML-RPC server, you need to use a third-party library like Apache XML-RPC.
// Here is a simple example using Apache XML-RPC:

import org.apache.xmlrpc.server.XmlRpcServer;
import org.apache.xmlrpc.webserver.WebServer;

public class Task111_MISTRAL_codestral_latest {
    public static void main(String[] args) throws Exception {
        WebServer webServer = new WebServer(8000);
        XmlRpcServer xmlRpcServer = webServer.getXmlRpcServer();

        xmlRpcServer.addHandler("add", new AddHandler());
        webServer.start();
    }
}

import java.util.Vector;
import org.apache.xmlrpc.XmlRpcException;
import org.apache.xmlrpc.server.XmlRpcHandler;

public class AddHandler implements XmlRpcHandler {
    public Object execute(Object[] params) throws XmlRpcException {
        int sum = 0;
        for (Object param : params) {
            sum += ((Integer) param).intValue();
        }
        return new Integer(sum);
    }
}