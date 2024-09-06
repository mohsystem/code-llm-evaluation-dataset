import javax.naming.Context;
import javax.naming.InitialContext;
import javax.naming.NamingException;

public class Task107_PERPLEXITY_llama_3_sonar_large_32k_chat {
    public static void main(String[] args) {
        try {
            Context ctx = new InitialContext();
            Object obj = ctx.lookup("java:comp/env/myResource");
            System.out.println("Lookup successful: " + obj);
        } catch (NamingException e) {
            System.out.println("Lookup failed: " + e.getMessage());
        }
    }
}