#include <ldap.h>
#include <iostream>
#include <string>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        std::cout << "Usage: " << argv[0] << " <domain_component> <username>" << std::endl;
        return 1;
    }
    std::string dc = argv[1];
    std::string username = argv[2];
    std::string query = "dc=" + dc + ",dc=com";
    std::string searchBase = "dc=" + dc + ",dc=com";
    std::string searchFilter = "uid=" + username;
    LDAP *ld;
    int rc;
    std::string ldapURL = "ldap://localhost:389";
    ld = ldap_init(ldapURL.c_str(), 389);
    if (ld == NULL) {
        std::cout << "Error initializing LDAP" << std::endl;
        return 1;
    }
    rc = ldap_bind_s(ld, "cn=admin,dc=localhost,dc=com", "password");
    if (rc != LDAP_SUCCESS) {
        std::cout << "Error binding to LDAP: " << ldap_err2string(rc) << std::endl;
        ldap_unbind(ld);
        return 1;
    }
    LDAPMessage *result;
    rc = ldap_search_ext_s(ld, searchBase.c_str(), LDAP_SCOPE_SUBTREE, searchFilter.c_str(), NULL, 0, NULL, NULL, &result);
    if (rc != LDAP_SUCCESS) {
        std::cout << "Error searching LDAP: " << ldap_err2string(rc) << std::endl;
        ldap_unbind(ld);
        return 1;
    }
    char **values;
    int i;
    for (; ldap_count_entries(ld, result) > 0; ldap_msgfree(result)) {
        result = ldap_first_entry(ld, result);
        values = ldap_get_values(ld, result, "objectClass");
        for (i = 0; values[i] != NULL; i++) {
            std::cout << ldap_get_dn(ld, result) << ": " << values[i] << std::endl;
        }
        ldap_value_free(values);
    }
    ldap_unbind(ld);
    return 0;
}