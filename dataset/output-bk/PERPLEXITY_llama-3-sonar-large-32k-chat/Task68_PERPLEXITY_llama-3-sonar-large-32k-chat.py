import sys
import ldap

def main():
    if len(sys.argv) != 3:
        print("Usage: python ldap_search.py <domain_component> <username>")
        sys.exit(1)
    dc = sys.argv[1]
    username = sys.argv[2]
    query = "dc=" + dc + ",dc=com"
    search_base = "dc=" + dc + ",dc=com"
    search_filter = "uid=" + username
    ldap_url = "ldap://localhost:389"
    conn = ldap.initialize(ldap_url)
    conn.simple_bind_s("cn=admin,dc=" + dc + ",dc=com", "password")
    result = conn.search_s(search_base, ldap.SCOPE_SUBTREE, search_filter)
    for dn, attrs in result:
        print(dn + ": " + str(attrs))
    conn.unbind_s()

if __name__ == "__main__":
    main()