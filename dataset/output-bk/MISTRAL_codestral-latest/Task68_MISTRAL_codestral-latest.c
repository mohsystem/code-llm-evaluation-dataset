#include <stdio.h>
#include <ldap.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <dc> <username>
", argv[0]);
        return 1;
    }

    char *dc = argv[1];
    char *username = argv[2];

    char *ldap_uri = "ldap://localhost:389";
    char search_base[256];
    snprintf(search_base, sizeof(search_base), "dc=%s", dc);
    char search_filter[256];
    snprintf(search_filter, sizeof(search_filter), "(uid=%s)", username);

    LDAP *ldap_handle;
    int result = ldap_initialize(&ldap_handle, ldap_uri);

    if (result != LDAP_SUCCESS) {
        fprintf(stderr, "Error: %s
", ldap_err2string(result));
        return 1;
    }

    struct ldap_message *search_result;
    result = ldap_search_s(ldap_handle, search_base, LDAP_SCOPE_SUBTREE, search_filter, NULL, 0, &search_result);

    if (result != LDAP_SUCCESS) {
        fprintf(stderr, "Error: %s
", ldap_err2string(result));
        ldap_unbind_ext_s(ldap_handle, NULL, NULL);
        return 1;
    }

    if (ldap_count_entries(ldap_handle, search_result) > 0) {
        struct berval **values;
        char *attribute_name = ldap_first_attribute(ldap_handle, ldap_first_entry(ldap_handle, search_result), &values);

        while (attribute_name != NULL) {
            printf("%s: %s
", attribute_name, values[0]->bv_val);
            attribute_name = ldap_next_attribute(ldap_handle, ldap_first_entry(ldap_handle, search_result), &values);
        }
    } else {
        printf("User not found.
");
    }

    ldap_msgfree(search_result);
    ldap_unbind_ext_s(ldap_handle, NULL, NULL);

    return 0;
}