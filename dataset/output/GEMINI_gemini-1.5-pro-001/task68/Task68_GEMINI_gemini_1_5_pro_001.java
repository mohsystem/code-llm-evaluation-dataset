import javax.naming.Context;
import javax.naming.NamingEnumeration;
import javax.naming.NamingException;
import javax.naming.directory.*;
import java.util.Hashtable;

public class Task68_GEMINI_gemini_1_5_pro_001 {

    public static void main(String[] args) {
        if (args.length != 2) {
            System.out.println("Usage: java Task68_GEMINI_gemini_1_5_pro_001 <username> <domain_component>");
            System.exit(1);
        }

        String username = args[0];
        String domainComponent = args[1];

        try {
            Hashtable<String, String> env = new Hashtable<>();
            env.put(Context.INITIAL_CONTEXT_FACTORY, "com.sun.jndi.ldap.LdapCtxFactory");
            env.put(Context.PROVIDER_URL, "ldap://localhost:389");
            DirContext ctx = new InitialDirContext(env);

            String baseDn = "dc=" + domainComponent.replace(".", ",dc=");
            String searchFilter = "(sAMAccountName=" + username + ")";
            SearchControls searchCtls = new SearchControls();
            searchCtls.setSearchScope(SearchControls.SUBTREE_SCOPE);
            String[] returnedAtts = {"cn", "mail", "memberOf"};
            searchCtls.setReturningAttributes(returnedAtts);

            NamingEnumeration<SearchResult> answer = ctx.search(baseDn, searchFilter, searchCtls);

            if (answer.hasMore()) {
                SearchResult result = answer.next();
                Attributes attributes = result.getAttributes();
                System.out.println(attributes);
            } else {
                System.out.println("User not found.");
            }

            ctx.close();
        } catch (NamingException e) {
            System.err.println("Error searching LDAP: " + e);
        }
    }
}