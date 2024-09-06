import ldap

def get_user_info(dc, username):
    ldap_server = "ldap://localhost"
    base_dn = f"dc={dc},dc=com"
    search_filter = f"(uid={username})"

    try:
        ldap_conn = ldap.initialize(ldap_server)
        ldap_conn.protocol_version = ldap.VERSION3
        ldap_conn.simple_bind_s()

        result = ldap_conn.search_s(base_dn, ldap.SCOPE_SUBTREE, search_filter)
        return result
    except ldap.LDAPError as e:
        print(f"Error: {e}")
    finally:
        ldap_conn.unbind()

if __name__ == "__main__":
    import sys
    if len(sys.argv) != 3:
        print("Usage: python script.py <dc> <username>")
        sys.exit(1)

    dc = sys.argv[1]
    username = sys.argv[2]

    user_info = get_user_info(dc, username)
    if user_info:
        print(user_info)
    else:
        print("User not found.")