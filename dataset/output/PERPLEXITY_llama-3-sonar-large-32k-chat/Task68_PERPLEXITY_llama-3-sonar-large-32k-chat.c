// C code is not possible in a single file as it requires separate files for different libraries.
// However, here is an example of how you can achieve this using the OpenLDAP library:
#include <ldap.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char** argv) {
    if (argc != 3) {
        printf("Usage: %s <domain_component> <username>\n", argv[0]);
        return 1;
    }
    char* dc = argv[1];
    char* username = argv[2];
    LDAP* conn = ldap_init("localhost", 389);
    int rc = ldap_bind_s(conn, NULL, NULL);
    if (rc != LDAP_SUCCESS) {
        printf("Error: %s\n", ldap_err2string(rc));
        return 1;
    }
    char baseDN[256];
    sprintf(baseDN, "dc=%s", dc);
    for (char* p = strchr(baseDN, '.'); p != NULL; p = strchr(p + 1, '.')) {
        *p = ',';
    }
    char query[256];
    sprintf(query, "(uid=%s)", username);
    LDAPMessage* result;
    rc = ldap_search_ext_s(conn, baseDN, LDAP_SCOPE_SUBTREE, query, NULL, NULL, NULL, &result);
    if (rc != LDAP_SUCCESS) {
        printf("Error: %s\n", ldap_err2string(rc));
        return 1;
    }
    for (; ldap_count_entries(conn, result) > 0; ldap_msgfree(result)) {
        result = ldap_first_entry(conn, result);
        char* dn = ldap_get_dn(conn, result);
        printf("%s\n", dn);
    }
    ldap_unbind_ext(conn, NULL, NULL);
    return 0;
}