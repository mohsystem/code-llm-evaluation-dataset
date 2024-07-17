
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ldap.h>

#define MAX_LENGTH 256

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <domain> <username>\
", argv[0]);
        return 1;
    }

    char *domain = argv[1];
    char *username = argv[2];

    LDAP *ld;
    int rc;
    char ldap_uri[MAX_LENGTH];
    char base_dn[MAX_LENGTH];
    char search_filter[MAX_LENGTH];

    snprintf(ldap_uri, MAX_LENGTH, "ldap://localhost:389");
    snprintf(base_dn, MAX_LENGTH, "dc=%s", domain);
    char *token = strtok(base_dn, ".");
    while (token != NULL) {
        snprintf(base_dn + strlen(base_dn), MAX_LENGTH - strlen(base_dn), ",dc=%s", token);
        token = strtok(NULL, ".");
    }
    memmove(base_dn, base_dn + 1, strlen(base_dn));

    snprintf(search_filter, MAX_LENGTH, "(uid=%s)", username);

    rc = ldap_initialize(&ld, ldap_uri);
    if (rc != LDAP_SUCCESS) {
        fprintf(stderr, "ldap_initialize failed: %s\
", ldap_err2string(rc));
        return 1;
    }

    rc = ldap_simple_bind_s(ld, NULL, NULL);
    if (rc != LDAP_SUCCESS) {
        fprintf(stderr, "ldap_simple_bind_s failed: %s\
", ldap_err2string(rc));
        ldap_unbind_ext_s(ld, NULL, NULL);
        return 1;
    }

    LDAPMessage *result;
    char *attrs[] = {"*", NULL};
    rc = ldap_search_ext_s(ld, base_dn, LDAP_SCOPE_SUBTREE, search_filter, attrs, 0, NULL, NULL, NULL, 0, &result);
    if (rc != LDAP_SUCCESS) {
        fprintf(stderr, "ldap_search_ext_s failed: %s\
", ldap_err2string(rc));
        ldap_unbind_ext_s(ld, NULL, NULL);
        return 1;
    }

    int num_entries = ldap_count_entries(ld, result);
    if (num_entries == 0) {
        printf("User not found\
");
    } else {
        LDAPMessage *entry = ldap_first_entry(ld, result);
        BerElement *ber;
        char *attribute;
        char **values;

        printf("User information:\
");
        for (attribute = ldap_first_attribute(ld, entry, &ber);
             attribute != NULL;
             attribute = ldap_next_attribute(ld, entry, ber)) {
            values = ldap_get_values(ld, entry, attribute);
            if (values != NULL) {
                printf("%s: %s\
", attribute, values[0]);
                ldap_value_free(values);
            }
            ldap_memfree(attribute);
        }
        if (ber != NULL) {
            ber_free(ber, 0);
        }
    }

    ldap_msgfree(result);
    ldap_unbind_ext_s(ld, NULL, NULL);
    return 0;
}
