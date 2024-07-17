import sys
from ldap3 import Server, Connection, ALL

if len(sys.argv) != 3:
    print(f"Usage: {sys.argv[0]} <dc> <username>")
    sys.exit(1)

dc = sys.argv[1]
username = sys.argv[2]

ldap_server = Server('localhost', port=389)
conn = Connection(ldap_server)

search_base = f'dc={dc}'
search_filter = f'(uid={username})'

conn.search(search_base, search_filter, attributes=ALL)

if len(conn.entries) > 0:
    print("User information:")
    for attribute in conn.entries[0].entry_attributes_as_dict:
        print(f"{attribute}: {conn.entries[0][attribute].values}")
else:
    print("User not found.")

conn.unbind()