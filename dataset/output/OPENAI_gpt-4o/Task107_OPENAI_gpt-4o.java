import javax.naming.Context;
import javax.naming.InitialContext;
import javax.naming.NamingException;
import java.util.Hashtable;

public class JNDILookup {
    public static void main(String[] args) {
        Hashtable<String, String> env = new Hashtable<>();
        env.put(Context.INITIAL_CONTEXT_FACTORY, "com.sun.jndi.fscontext.RefFSContextFactory");
        env.put(Context.PROVIDER_URL, "file:///tmp");

        try {
            Context ctx = new InitialContext(env);
            Object obj = ctx.lookup("example/resource");
            System.out.println("Java JNDI lookup result: " + obj);
        } catch (NamingException e) {
            e.printStackTrace();
        }
    }
}