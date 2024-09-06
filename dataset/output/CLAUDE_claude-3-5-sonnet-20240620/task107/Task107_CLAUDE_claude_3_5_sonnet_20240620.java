
import javax.naming.Context;
import javax.naming.InitialContext;
import javax.naming.NamingException;
import javax.sql.DataSource;

public class Task107_CLAUDE_claude_3_5_sonnet_20240620 {
    public static void main(String[] args) {
        try {
            // Create an initial context
            Context ctx = new InitialContext();

            // Perform JNDI lookup for a DataSource
            DataSource ds = (DataSource) ctx.lookup("java:comp/env/jdbc/MyDataSource");

            // Perform JNDI lookup for a custom object
            Object customObject = ctx.lookup("java:comp/env/customObject");

            System.out.println("DataSource: " + ds);
            System.out.println("Custom Object: " + customObject);

            // Close the context
            ctx.close();
        } catch (NamingException e) {
            e.printStackTrace();
        }
    }
}
