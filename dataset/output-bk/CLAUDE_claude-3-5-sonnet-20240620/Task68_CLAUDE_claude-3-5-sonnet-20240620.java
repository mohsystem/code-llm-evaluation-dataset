
import javax.naming.Context;
import javax.naming.NamingEnumeration;
import javax.naming.NamingException;
import javax.naming.directory.*;

public class LDAPSearch {
    public static void main(String[] args) {
        if (args.length != 2) {
            System.out.println("Usage: java LDAPSearch <domain> <username>");
            return;
        }

        String domain = args[0];
        String username = args[1];

        DirContext ctx = null;
        try {
            String ldapURL = "ldap://localhost:389";
            String baseDN = "dc=" + domain.replace(".", ",dc=");

            InitialDirContext env = new InitialDirContext();
            env.addToEnvironment(Context.INITIAL_CONTEXT_FACTORY, "com.sun.jndi.ldap.LdapCtxFactory");
            env.addToEnvironment(Context.PROVIDER_URL, ldapURL);

            ctx = new InitialDirContext(env);

            String searchFilter = "(uid=" + username + ")";
            SearchControls searchControls = new SearchControls();
            searchControls.setSearchScope(SearchControls.SUBTREE_SCOPE);

            NamingEnumeration<SearchResult> results = ctx.search(baseDN, searchFilter, searchControls);

            if (results.hasMore()) {
                SearchResult result = results.next();
                Attributes attrs = result.getAttributes();
                NamingEnumeration<? extends Attribute> attributes = attrs.getAll();

                System.out.println("User information:");
                while (attributes.hasMore()) {
                    Attribute attr = attributes.next();
                    System.out.println(attr.getID() + ": " + attr.get());
                }
            } else {
                System.out.println("User not found");
            }
        } catch (NamingException e) {
            e.printStackTrace();
        } finally {
            if (ctx != null) {
                try {
                    ctx.close();
                } catch (NamingException e) {
                    e.printStackTrace();
                }
            }
        }
    }
}
