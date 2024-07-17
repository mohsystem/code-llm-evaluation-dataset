#include <ldap.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <domain_component> <username>
", argv[0]);
        return 1;
    }
    char *dc = argv[1];
    char *username = argv[2];
    char query[256];
    sprintf(query, "dc=%s,dc=com", dc);
    char searchBase[256];
    sprintf(searchBase, "dc=%s,dc=com", dc);
    char searchFilter[256];
    sprintf(searchFilter, "uid=%s", username);
    LDAP *ld;
    int rc;
    char *ldapURL = "ldap://localhost:389";
    ld = ldap_init(ldapURL, 389);
    if (ld == NULL) {
        printf("Error initializing LDAP
");
        return 1;
    }
    rc = ldap_bind_s(ld, "cn=admin,dc=localhost,dc=com", "password");
    if (rc != LDAP_SUCCESS) {
        printf("Error binding to LDAP: %s
", ldap_err2string(rc));
        ldap_unbind(ld);
        return 1;
    }
    LDAPMessage *result;
    rc = ldap_search_ext_s(ld, searchBase, LDAP_SCOPE_SUBTREE, searchFilter, NULL, 0, NULL, NULL, &result);
    if (rc != LDAP_SUCCESS) {
        printf("Error searching LDAP: %s
", ldap_err2string(rc));
        ldap_unbind(ld);
        return 1;
    }
    char **values;
    int i;
    for (; ldap_count_entries(ld, result) > 0; ldap_msgfree(result)) {
        result = ldap_first_entry(ld, result);
        values = ldap_get_values(ld, result, "objectClass");
        for (i = 0; values[i] != NULL; i++) {
            printf("%s: %s
", ldap_get_dn(ld, result), values[i]);
        }
        ldap_value_free(values);
    }
    ldap_unbind(ld);
    return 0;
}