import javax.naming.Context;
import javax.naming.InitialContext;
import javax.naming.NamingException;

public class JNDILookup {
    public static void main(String[] args) {
        try {
            Context ctx = new InitialContext();
            Object obj = ctx.lookup("java:comp/env/myResource");
            System.out.println("Lookup successful: " + obj);
        } catch (NamingException e) {
            System.err.println("Error during JNDI lookup: " + e.getMessage());
        }
    }
}