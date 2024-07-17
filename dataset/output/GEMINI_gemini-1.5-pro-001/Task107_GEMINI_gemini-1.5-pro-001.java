import javax.naming.Context;
import javax.naming.InitialContext;
import javax.naming.NamingException;

public class JndiLookup {

    public static void main(String[] args) {

        try {
            // Set up the JNDI context
            Context context = new InitialContext();

            // Specify the JNDI name of the resource
            String jndiName = "java:comp/env/myDataSource"; 

            // Perform the JNDI lookup
            Object resource = context.lookup(jndiName);

            // Check the type of the retrieved resource
            if (resource instanceof javax.sql.DataSource) {
                System.out.println("Retrieved resource is a DataSource: " + resource.toString());
            } else {
                System.out.println("Retrieved resource is not a DataSource: " + resource.getClass().getName());
            }

        } catch (NamingException e) {
            System.err.println("JNDI lookup failed: " + e.getMessage());
            e.printStackTrace();
        }
    }
}