
import ldap

def main():
    ldap_uri = "ldap://localhost:389"
    
    try:
        # Initialize LDAP connection
        ld = ldap.initialize(ldap_uri)
        
        # Perform simple bind
        ld.simple_bind_s("cn=admin,dc=example,dc=com", "admin_password")
        print("LDAP connection and bind successful")
        
        # Perform LDAP search (simulating JNDI lookup)
        base = "ou=users,dc=example,dc=com"
        search_filter = "(objectClass=*)"
        
        result = ld.search_s(base, ldap.SCOPE_SUBTREE, search_filter)
        print("LDAP search successful")
        
        # Process and print results
        for dn, entry in result:
            print(f"DN: {dn}")
            for attr, values in entry.items():
                for value in values:
                    print(f"{attr}: {value.decode(\'utf-8\')}")
            print()
        
    except ldap.LDAPError as e:
        print(f"LDAP error: {e}")
    
    finally:
        # Unbind and free resources
        if \'ld\' in locals():
            ld.unbind_s()

if __name__ == "__main__":
    main()
