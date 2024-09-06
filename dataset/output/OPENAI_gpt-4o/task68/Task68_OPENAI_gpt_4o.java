import javax.naming.Context;
import javax.naming.NamingEnumeration;
import javax.naming.directory.*;
import java.util.Hashtable;
import com.google.gson.Gson;

public class Task68_OPENAI_gpt_4o {
    public static void main(String[] args) {
        String domainComponent = args[0];
        String username = args[1];
        
        String ldapHost = "ldap://localhost";
        String searchBase = "dc=" + domainComponent;
        String searchFilter = "(uid=" + username + ")";
        
        Hashtable<String, String> env = new Hashtable<>();
        env.put(Context.INITIAL_CONTEXT_FACTORY, "com.sun.jndi.ldap.LdapCtxFactory");
        env.put(Context.PROVIDER_URL, ldapHost);
        
        try {
            DirContext context = new InitialDirContext(env);
            SearchControls controls = new SearchControls();
            controls.setSearchScope(SearchControls.SUBTREE_SCOPE);
            
            NamingEnumeration<SearchResult> results = context.search(searchBase, searchFilter, controls);
            Gson gson = new Gson();
            while (results.hasMore()) {
                SearchResult result = results.next();
                System.out.println(gson.toJson(result));
            }
            context.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}