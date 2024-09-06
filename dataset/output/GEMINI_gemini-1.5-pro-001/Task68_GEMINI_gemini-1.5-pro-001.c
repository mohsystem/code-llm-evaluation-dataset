#include <stdio.h>
#include <ldap.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <username> <domain_component>\n", argv[0]);
        return 1;
    }

    char *username = argv[1];
    char *domainComponent = argv[2];

    LDAP *ld;
    LDAPMessage *result;
    LDAPMessage *entry;
    int rc;
    char *attr;
    BerElement *ber;
    char **vals;

    // Initialize LDAP
    if (ldap_initialize(&ld, "ldap://localhost") != LDAP_SUCCESS) {
        fprintf(stderr, "LDAP initialization failed\n");
        return 1;
    }

    // Bind to the server
    if (ldap_simple_bind_s(ld, NULL, NULL) != LDAP_SUCCESS) {
        fprintf(stderr, "LDAP bind failed\n");
        ldap_unbind_ext_s(ld, NULL, NULL);
        return 1;
    }

    // Construct the search base DN
    char baseDn[256];
    snprintf(baseDn, sizeof(baseDn), "dc=%s", domainComponent);
    char *token = strtok(baseDn, ".");
    while (token != NULL) {
        strcat(baseDn, ",dc=");
        strcat(baseDn, token);
        token = strtok(NULL, ".");
    }

    // Construct the search filter
    char searchFilter[256];
    snprintf(searchFilter, sizeof(searchFilter), "(sAMAccountName=%s)", username);

    // Perform the search
    rc = ldap_search_ext_s(ld, baseDn, LDAP_SCOPE_SUBTREE,
                          searchFilter, NULL, 0,
                          NULL, NULL, NULL, 0, &result);

    if (rc == LDAP_SUCCESS) {
        if (ldap_count_entries(ld, result) > 0) {
            entry = ldap_first_entry(ld, result);
            while (entry != NULL) {
                // Get the DN of the entry
                char *dn = ldap_get_dn(ld, entry);
                printf("dn: %s\n", dn);
                ldap_memfree(dn);

                // Iterate over the attributes
                for (attr = ldap_first_attribute(ld, entry, &ber);
                     attr != NULL; attr = ldap_next_attribute(ld, entry, ber)) {
                    // Get the values of the attribute
                    vals = ldap_get_values(ld, entry, attr);
                    if (vals != NULL) {
                        printf("%s: ", attr);
                        for (int i = 0; vals[i] != NULL; i++) {
                            printf("%s ", vals[i]);
                        }
                        printf("\n");
                        ldap_value_free(vals);
                    }
                    ldap_memfree(attr);
                }
                printf("\n");
                entry = ldap_next_entry(ld, entry);
            }
        } else {
            printf("User not found.\n");
        }
        ldap_msgfree(result);
    } else {
        fprintf(stderr, "LDAP search failed: %s\n", ldap_err2string(rc));
    }

    ldap_unbind_ext_s(ld, NULL, NULL);
    return 0;
}