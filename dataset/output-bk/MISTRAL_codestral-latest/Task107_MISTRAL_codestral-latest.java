import javax.naming.*;
import javax.naming.directory.*;

public class JNDILookup {
    public static void main(String[] args) {
        try {
            Context ctx = new InitialContext();
            Object obj = ctx.lookup("java:comp/env/jdbc/MyDB");
            System.out.println("Object found: " + obj);
        } catch (NamingException e) {
            e.printStackTrace();
        }
    }
}