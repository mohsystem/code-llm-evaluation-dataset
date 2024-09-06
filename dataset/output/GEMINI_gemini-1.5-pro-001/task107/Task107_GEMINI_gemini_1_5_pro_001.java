import java.util.Hashtable;
import javax.naming.Context;
import javax.naming.InitialContext;
import javax.naming.NamingException;

public class Task107_GEMINI_gemini_1_5_pro_001 {

    public static void main(String[] args) {

        // Set up JNDI environment
        Hashtable<String, Object> env = new Hashtable<>();
        env.put(Context.INITIAL_FACTORY, "com.sun.jndi.dns.DnsContextFactory");
        env.put(Context.PROVIDER_URL, "dns://localhost");

        try {
            // Create initial context
            Context ctx = new InitialContext(env);

            // Perform JNDI lookup
            Object obj = ctx.lookup("example.com/MyObject");
            System.out.println("Retrieved object: " + obj);

        } catch (NamingException e) {
            System.err.println("Error during JNDI lookup: " + e.getMessage());
        }
    }
}