import ldap

def jndi_lookup():
    ldap_host = "ldap.example.com"
    ldap_port = 389
    base_dn = "dc=example,dc=com"
    filter = "(objectClass=*)"

    conn = ldap.initialize(f"ldap://{ldap_host}:{ldap_port}")
    conn.bind_s("", "")

    result = conn.search_s(base_dn, ldap.SCOPE_SUBTREE, filter)
    for dn, entry in result:
        print(f"DN: {dn}, Entry: {entry}")

    conn.unbind_s()

if __name__ == "__main__":
    jndi_lookup()