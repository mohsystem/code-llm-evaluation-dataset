import ldap
import sys

def main():
    if len(sys.argv) != 3:
        print("Usage: python ldap_search.py <domain> <username>")
        sys.exit(1)

    domain_component = sys.argv[1]
    username = sys.argv[2]

    ldap_query = f"(&(objectClass=user)(sAMAccountName={username}))"
    search_base = "dc=" + domain_component.replace(".", ",dc=")

    try:
        l = ldap.initialize("ldap://localhost:389")
        l.simple_bind_s()

        search_result = l.search_s(search_base, ldap.SCOPE_SUBTREE, ldap_query)

        if search_result:
            dn, attributes = search_result[0]
            print(f"dn: {dn.decode()}")
            for attr, value in attributes.items():
                print(f"{attr.decode()}: {value[0].decode()}")
        else:
            print("User not found.")

        l.unbind_s()

    except ldap.LDAPError as e:
        print(f"LDAP Error: {e}")

if __name__ == "__main__":
    main()