import ldap
import sys

def get_ldap_user_info(username, domain_component):
    ldap_server = "ldap://localhost"
    base_dn = f"dc={domain_component.replace('.', ',dc=')}"
    search_filter = f"(sAMAccountName={username})"
    attributes = ["cn", "mail", "memberOf"]

    try:
        conn = ldap.initialize(ldap_server)
        conn.simple_bind_s()
        result = conn.search_s(base_dn, ldap.SCOPE_SUBTREE, search_filter, attributes)

        if result:
            user_info = result[0][1]
            return user_info
        else:
            return None

    except Exception as e:
        print(f"An error occurred: {e}")
        return None

if __name__ == "__main__":
    if len(sys.argv) != 3:
        print("Usage: python ldap_query.py <username> <domain_component>")
        sys.exit(1)

    username = sys.argv[1]
    domain_component = sys.argv[2]

    user_info = get_ldap_user_info(username, domain_component)

    if user_info:
        print(user_info)
    else:
        print("User not found.")