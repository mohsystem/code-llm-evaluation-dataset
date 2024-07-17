import java.util.Hashtable;
import javax.naming.Context;
import javax.naming.NamingEnumeration;
import javax.naming.directory.Attributes;
import javax.naming.directory.DirContext;
import javax.naming.directory.InitialDirContext;
import javax.naming.directory.SearchControls;
import javax.naming.directory.SearchResult;

public class LDAPQuery {
    public static void main(String[] args) {
        if (args.length != 2) {
            System.out.println("Usage: java LDAPQuery <dc> <username>");
            System.exit(1);
        }

        String dc = args[0];
        String username = args[1];

        String ldapURL = "ldap://localhost:389";
        String searchBase = "dc=" + dc;
        String searchFilter = "(uid=" + username + ")";

        Hashtable<String, String> env = new Hashtable<>();
        env.put(Context.INITIAL_CONTEXT_FACTORY, "com.sun.jndi.ldap.LdapCtxFactory");
        env.put(Context.PROVIDER_URL, ldapURL);

        try {
            DirContext ctx = new InitialDirContext(env);
            SearchControls searchControls = new SearchControls();
            searchControls.setSearchScope(SearchControls.SUBTREE_SCOPE);

            NamingEnumeration<SearchResult> results = ctx.search(searchBase, searchFilter, searchControls);

            if (results.hasMore()) {
                SearchResult searchResult = results.next();
                Attributes attributes = searchResult.getAttributes();
                System.out.println("User information: " + attributes);
            } else {
                System.out.println("User not found.");
            }

            ctx.close();
        } catch (Exception e) {
            System.err.println("Error: " + e.getMessage());
        }
    }
}