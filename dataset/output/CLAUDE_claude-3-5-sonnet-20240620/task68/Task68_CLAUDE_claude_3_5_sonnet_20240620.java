
import javax.naming.Context;
import javax.naming.NamingEnumeration;
import javax.naming.NamingException;
import javax.naming.directory.*;
import java.util.Hashtable;

public class Task68_CLAUDE_claude_3_5_sonnet_20240620 {
    public static void main(String[] args) {
        if (args.length != 1) {
            System.out.println("Usage: java Task68_CLAUDE_claude_3_5_sonnet_20240620 <username@domain.com>");
            System.exit(1);
        }

        String inputString = args[0];
        String[] parts = extractDcAndUsername(inputString);
        String username = parts[0];
        String dc = parts[1];

        searchLDAP(username, dc);
    }

    private static String[] extractDcAndUsername(String inputString) {
        String[] parts = inputString.split("@");
        String username = parts[0];
        String[] domainParts = parts[1].split("\\\\.");
        StringBuilder dcBuilder = new StringBuilder();
        for (String part : domainParts) {
            dcBuilder.append("dc=").append(part).append(",");
        }
        String dc = dcBuilder.substring(0, dcBuilder.length() - 1);
        return new String[]{username, dc};
    }

    private static void searchLDAP(String username, String dc) {
        Hashtable<String, Object> env = new Hashtable<>();
        env.put(Context.INITIAL_CONTEXT_FACTORY, "com.sun.jndi.ldap.LdapCtxFactory");
        env.put(Context.PROVIDER_URL, "ldap://localhost:389");

        try {
            DirContext ctx = new InitialDirContext(env);
            SearchControls searchControls = new SearchControls();
            searchControls.setSearchScope(SearchControls.SUBTREE_SCOPE);

            String searchFilter = "(sAMAccountName=" + username + ")";
            NamingEnumeration<SearchResult> results = ctx.search(dc, searchFilter, searchControls);

            if (results.hasMore()) {
                SearchResult result = results.next();
                Attributes attrs = result.getAttributes();
                System.out.println("User Information:");
                NamingEnumeration<? extends Attribute> attributes = attrs.getAll();
                while (attributes.hasMore()) {
                    Attribute attr = attributes.next();
                    System.out.println(attr.getID() + ": " + attr.get());
                }
            } else {
                System.out.println("User not found.");
            }

            ctx.close();
        } catch (NamingException e) {
            System.out.println("LDAP Error: " + e.getMessage());
        }
    }
}
