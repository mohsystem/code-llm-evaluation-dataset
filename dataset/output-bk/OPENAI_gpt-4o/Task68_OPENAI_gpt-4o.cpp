#include <iostream>
#include <string>
#include <ldap.h>

int main(int argc, char *argv[]) {
    std::string domainComponent = argv[1];
    std::string username = argv[2];

    LDAP *ldap;
    LDAPMessage *result, *entry;
    int version = LDAP_VERSION3;
    int rc;
    std::string search_base = "DC=" + domainComponent + ",DC=com";
    std::string filter = "(sAMAccountName=" + username + ")";

    rc = ldap_initialize(&ldap, "ldap://localhost");
    ldap_set_option(ldap, LDAP_OPT_PROTOCOL_VERSION, &version);

    rc = ldap_search_ext_s(ldap, search_base.c_str(), LDAP_SCOPE_SUBTREE, filter.c_str(), NULL, 0, NULL, NULL, NULL, 100, &result);
    if (rc == LDAP_SUCCESS) {
        for (entry = ldap_first_entry(ldap, result); entry != NULL; entry = ldap_next_entry(ldap, entry)) {
            char *dn = ldap_get_dn(ldap, entry);
            std::cout << "dn: " << dn << std::endl;
            ldap_memfree(dn);
        }
        ldap_msgfree(result);
    } else {
        std::cerr << "Error: " << ldap_err2string(rc) << std::endl;
    }

    ldap_unbind_ext(ldap, NULL, NULL);
    return 0;
}