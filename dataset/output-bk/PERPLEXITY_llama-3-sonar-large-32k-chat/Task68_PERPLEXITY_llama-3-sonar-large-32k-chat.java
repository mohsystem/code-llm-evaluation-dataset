import java.util.Hashtable;
import javax.naming.Context;
import javax.naming.directory.DirContext;
import javax.naming.directory.SearchControls;
import javax.naming.directory.SearchResult;
import javax.naming.ldap.InitialLdapContext;
import javax.naming.ldap.LdapContext;

public class LDAPSearch {
    public static void main(String[] args) {
        if (args.length != 2) {
            System.out.println("Usage: java LDAPSearch <domain_component> <username>");
            System.exit(1);
        }
        String dc = args[0];
        String username = args[1];
        String ldapURL = "ldap://localhost:389";
        String query = "dc=" + dc + ",dc=com";
        String searchBase = "dc=" + dc + ",dc=com";
        String searchFilter = "uid=" + username;
        Hashtable<String, String> env = new Hashtable<String, String>();
        env.put(Context.INITIAL_CONTEXT_FACTORY, "com.sun.jndi.ldap.LdapCtxFactory");
        env.put(Context.PROVIDER_URL, ldapURL);
        env.put(Context.SECURITY_AUTHENTICATION, "simple");
        env.put(Context.SECURITY_PRINCIPAL, "cn=admin,dc=" + dc + ",dc=com");
        env.put(Context.SECURITY_CREDENTIALS, "password");
        try {
            LdapContext ctx = new InitialLdapContext(env, null);
            SearchControls constraints = new SearchControls();
            constraints.setSearchScope(SearchControls.SUBTREE_SCOPE);
            NamingEnumeration<SearchResult> results = ctx.search(searchBase, searchFilter, constraints);
            while (results.hasMore()) {
                SearchResult result = results.next();
                System.out.println(result.getName() + ": " + result.getAttributes());
            }
            ctx.close();
        } catch (Exception e) {
            System.out.println("Error: " + e.getMessage());
        }
    }
}