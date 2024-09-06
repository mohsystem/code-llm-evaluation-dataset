# Python does not natively support JNDI. You may use other libraries or methods for similar functionality.
import ldap

def jndi_lookup_python():
    server = "ldap://localhost:389"
    base = "dc=example,dc=com"
    scope = ldap.SCOPE_SUBTREE
    filterstr = "(ou=People)"
    
    try:
        conn = ldap.initialize(server)
        conn.protocol_version = ldap.VERSION3
        conn.simple_bind_s()  
        result = conn.search_s(base, scope, filterstr)
        
        for dn, entry in result:
            print(f"Distinguished Name: {dn}")
            for attr, values in entry.items():
                for value in values:
                    print(f"{attr}: {value}")
                    
    except ldap.LDAPError as e:
        print(f"LDAP error: {e}")
    finally:
        conn.unbind_s()

jndi_lookup_python()