
import sys
import ldap

def extract_dc_and_username(input_string):
    parts = input_string.split('@')
    username = parts[0]
    domain = parts[1].split('.')
    dc = ','.join([f"dc={part}" for part in domain])
    return username, dc

def search_ldap(username, dc):
    ldap_server = "ldap://localhost:389"
    conn = ldap.initialize(ldap_server)
    
    search_filter = f"(sAMAccountName={username})"
    base_dn = dc
    
    try:
        result = conn.search_s(base_dn, ldap.SCOPE_SUBTREE, search_filter)
        if result:
            return result[0][1]
        else:
            return None
    except ldap.LDAPError as e:
        print(f"LDAP Error: {e}")
        return None
    finally:
        conn.unbind()

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: python script.py <username@domain.com>")
        sys.exit(1)

    input_string = sys.argv[1]
    username, dc = extract_dc_and_username(input_string)
    
    user_info = search_ldap(username, dc)
    if user_info:
        print("User Information:")
        for key, value in user_info.items():
            print(f"{key}: {value}")
    else:
        print("User not found or error occurred.")
