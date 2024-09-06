import javax.naming.*;
import javax.naming.directory.*;
import java.util.Hashtable;

public class Task107_OPENAI_gpt_4o {
    public static void jndiLookupJava() {
        Hashtable<String, String> env = new Hashtable<>();
        env.put(Context.INITIAL_CONTEXT_FACTORY, "com.sun.jndi.ldap.LdapCtxFactory");
        env.put(Context.PROVIDER_URL, "ldap://localhost:389");

        try {
            DirContext ctx = new InitialDirContext(env);
            String searchFilter = "(ou=People)";
            String searchBase = "dc=example,dc=com";
            SearchControls searchControls = new SearchControls();
            searchControls.setSearchScope(SearchControls.SUBTREE_SCOPE);

            NamingEnumeration<SearchResult> results = ctx.search(searchBase, searchFilter, searchControls);

            while (results.hasMore()) {
                SearchResult searchResult = results.next();
                Attributes attributes = searchResult.getAttributes();
                NamingEnumeration<? extends Attribute> allAttributes = attributes.getAll();
                while (allAttributes.hasMore()) {
                    Attribute attr = allAttributes.next();
                    System.out.println(attr.getID() + ": " + attr.get());
                }
            }
            ctx.close();
        } catch (NamingException e) {
            System.err.println("JNDI lookup failed: " + e.getMessage());
        }
    }

    public static void main(String[] args) {
        jndiLookupJava();
    }
}