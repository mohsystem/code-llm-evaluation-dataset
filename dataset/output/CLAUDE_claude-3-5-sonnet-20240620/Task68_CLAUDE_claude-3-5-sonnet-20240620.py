
import sys
import ldap

def main():
    if len(sys.argv) != 3:
        print(f"Usage: {sys.argv[0]} <domain> <username>")
        return 1

    domain = sys.argv[1]
    username = sys.argv[2]

    ldap_uri = "ldap://localhost:389"
    base_dn = ",".join([f"dc={part}" for part in domain.split(".")])
    search_filter = f"(uid={username})"

    try:
        ld = ldap.initialize(ldap_uri)
        ld.simple_bind_s("", "")

        result = ld.search_s(base_dn, ldap.SCOPE_SUBTREE, search_filter)

        if not result:
            print("User not found")
        else:
            print("User information:")
            for dn, attrs in result:
                for attr, values in attrs.items():
                    print(f"{attr}: {values[0].decode(\'utf-8\')}")

    except ldap.LDAPError as e:
        print(f"LDAP error: {e}")
        return 1
    finally:
        ld.unbind_s()

    return 0

if __name__ == "__main__":
    sys.exit(main())
