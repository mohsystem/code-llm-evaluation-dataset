#include <stdio.h>
#include <ldap.h>
#include <string.h>
#include <stdlib.h>
#include <json-c/json.h>

int main(int argc, char *argv[]) {
    char *domainComponent = argv[1];
    char *username = argv[2];

    char query[256];
    snprintf(query, sizeof(query), "(uid=%s)", username);
    
    LDAP *ld;
    LDAPMessage *result, *entry;
    int ldap_version = LDAP_VERSION3;

    if (ldap_initialize(&ld, "ldap://localhost") != LDAP_SUCCESS) {
        fprintf(stderr, "LDAP initialization failed\n");
        return 1;
    }

    ldap_set_option(ld, LDAP_OPT_PROTOCOL_VERSION, &ldap_version);

    if (ldap_simple_bind_s(ld, NULL, NULL) != LDAP_SUCCESS) {
        fprintf(stderr, "LDAP bind failed\n");
        return 1;
    }

    char base_dn[256];
    snprintf(base_dn, sizeof(base_dn), "dc=%s", domainComponent);
    if (ldap_search_ext_s(ld, base_dn, LDAP_SCOPE_SUBTREE, query, NULL, 0, NULL, NULL, NULL, LDAP_NO_LIMIT, &result) != LDAP_SUCCESS) {
        fprintf(stderr, "LDAP search failed\n");
        return 1;
    }

    struct json_object *root = json_object_new_array();
    for (entry = ldap_first_entry(ld, result); entry != NULL; entry = ldap_next_entry(ld, entry)) {
        char *dn = ldap_get_dn(ld, entry);
        struct json_object *user_info = json_object_new_object();
        json_object_object_add(user_info, "dn", json_object_new_string(dn));
        json_object_array_add(root, user_info);
        ldap_memfree(dn);
    }
    printf("%s\n", json_object_to_json_string(root));

    ldap_msgfree(result);
    ldap_unbind_ext_s(ld, NULL, NULL);
    return 0;
}