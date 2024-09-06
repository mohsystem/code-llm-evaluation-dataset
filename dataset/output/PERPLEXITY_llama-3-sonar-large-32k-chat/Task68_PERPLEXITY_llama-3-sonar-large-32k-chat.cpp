// C++ code is not possible in a single file as it requires separate files for different classes and libraries.
// However, here is an example of how you can achieve this using the OpenLDAP library:
#include <ldap.h>
#include <iostream>
#include <string>

int main(int argc, char** argv) {
    if (argc != 3) {
        std::cout << "Usage: " << argv[0] << " <domain_component> <username>" << std::endl;
        return 1;
    }
    std::string dc = argv[1];
    std::string username = argv[2];
    LDAP* conn = ldap_init("localhost", 389);
    int rc = ldap_bind_s(conn, NULL, NULL);
    if (rc != LDAP_SUCCESS) {
        std::cout << "Error: " << ldap_err2string(rc) << std::endl;
        return 1;
    }
    std::string baseDN = "dc=" + dc.replace(dc.find('.'), 1, ",dc=");
    std::string query = "(uid=" + username + ")";
    LDAPMessage* result;
    rc = ldap_search_ext_s(conn, baseDN.c_str(), LDAP_SCOPE_SUBTREE, query.c_str(), NULL, NULL, NULL, &result);
    if (rc != LDAP_SUCCESS) {
        std::cout << "Error: " << ldap_err2string(rc) << std::endl;
        return 1;
    }
    for (; ldap_count_entries(conn, result) > 0; ldap_msgfree(result)) {
        result = ldap_first_entry(conn, result);
        std::string dn = ldap_get_dn(conn, result);
        std::cout << dn << std::endl;
    }
    ldap_unbind_ext(conn, NULL, NULL);
    return 0;
}