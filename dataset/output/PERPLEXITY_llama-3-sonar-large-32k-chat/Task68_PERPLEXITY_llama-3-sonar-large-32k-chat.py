import sys
import ldap

def ldap_search(dc, username):
    conn = ldap.initialize('ldap://localhost')
    conn.simple_bind_s()
    base_dn = 'dc=' + dc.replace('.', ',dc=')
    query = '(uid=' + username + ')'
    result = conn.search_s(base_dn, ldap.SCOPE_SUBTREE, query)
    return result

if __name__ == "__main__":
    if len(sys.argv) != 3:
        print("Usage: python ldap_search.py <domain_component> <username>")
        sys.exit(1)
    dc = sys.argv[1]
    username = sys.argv[2]
    result = ldap_search(dc, username)
    for dn, info in result:
        print(dn, info)