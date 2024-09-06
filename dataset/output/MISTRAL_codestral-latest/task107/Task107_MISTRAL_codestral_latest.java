import javax.naming.Context;
import javax.naming.InitialContext;
import javax.naming.NamingException;

public class Task107_MISTRAL_codestral_latest {
    public static void main(String[] args) {
        try {
            Context ctx = new InitialContext();
            Object lookup = ctx.lookup("java:comp/env/jdbc/MyDB");
            // Use the lookup object here
        } catch (NamingException e) {
            e.printStackTrace();
        }
    }
}