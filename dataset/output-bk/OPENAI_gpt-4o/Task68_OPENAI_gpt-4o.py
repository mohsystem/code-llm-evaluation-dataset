import sys
import ldap

def main():
    domain_component = sys.argv[1]
    username = sys.argv[2]
    
    ldap_url = "ldap://localhost"
    search_base = f"DC={domain_component},DC=com"
    search_filter = f"(sAMAccountName={username})"
    
    conn = ldap.initialize(ldap_url)
    conn.protocol_version = ldap.VERSION3
    
    try:
        result = conn.search_s(search_base, ldap.SCOPE_SUBTREE, search_filter)
        for dn, entry in result:
            print(f'dn: {dn}')
            for attr in entry:
                print(f'{attr}: {entry[attr]}')
    except ldap.LDAPError as e:
        print(e)
    finally:
        conn.unbind()
    
if __name__ == "__main__":
    main()