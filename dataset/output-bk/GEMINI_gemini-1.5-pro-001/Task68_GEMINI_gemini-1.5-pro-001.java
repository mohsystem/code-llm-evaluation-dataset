import javax.naming.Context;
import javax.naming.NamingEnumeration;
import javax.naming.NamingException;
import javax.naming.directory.*;
import java.util.Hashtable;

public class LDAPUserSearch {

    public static void main(String[] args) {

        if (args.length != 2) {
            System.out.println("Usage: java LDAPUserSearch <domain> <username>");
            return;
        }

        String domainComponent = args[0];
        String username = args[1];

        String ldapQuery = String.format("(&(objectClass=user)(sAMAccountName=%s))", username);

        Hashtable<String, String> env = new Hashtable<>();
        env.put(Context.INITIAL_CONTEXT_FACTORY, "com.sun.jndi.ldap.LdapCtxFactory");
        env.put(Context.PROVIDER_URL, "ldap://localhost:389");
        env.put(Context.SECURITY_AUTHENTICATION, "none");

        try (DirContext ctx = new InitialDirContext(env)) {

            SearchControls searchCtls = new SearchControls();
            searchCtls.setSearchScope(SearchControls.SUBTREE_SCOPE);
            String searchBase = "dc=" + domainComponent.replace(".", ",dc=");

            NamingEnumeration<SearchResult> answer = ctx.search(searchBase, ldapQuery, searchCtls);

            if (answer.hasMoreElements()) {
                SearchResult sr = answer.next();
                Attributes attrs = sr.getAttributes();
                System.out.println(attrs.toString());
            } else {
                System.out.println("User not found.");
            }

        } catch (NamingException e) {
            System.err.println("LDAP Error: " + e.getMessage());
        }
    }
}