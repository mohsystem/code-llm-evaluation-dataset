import ldap
import sys
import json

def main(args):
    domain_component = args[1]
    username = args[2]
    
    query = f"(uid={username})"
    
    try:
        conn = ldap.initialize('ldap://localhost')
        conn.simple_bind_s()
        results = conn.search_s(f"dc={domain_component}", ldap.SCOPE_SUBTREE, query)
        user_info = json.dumps(results)
        print(user_info)
    except ldap.LDAPError as e:
        print(f"LDAP error: {e}")

if __name__ == "__main__":
    main(sys.argv)