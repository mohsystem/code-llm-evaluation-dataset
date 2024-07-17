
#include <iostream>
#include <ldap.h>

int main() {
    LDAP *ld;
    int rc;
    std::string ldapuri = "ldap://localhost:389";
    
    // Initialize LDAP connection
    rc = ldap_initialize(&ld, ldapuri.c_str());
    if (rc != LDAP_SUCCESS) {
        std::cerr << "LDAP initialization failed: " << ldap_err2string(rc) << std::endl;
        return 1;
    }
    
    // Perform simple bind
    rc = ldap_simple_bind_s(ld, "cn=admin,dc=example,dc=com", "admin_password");
    if (rc != LDAP_SUCCESS) {
        std::cerr << "LDAP bind failed: " << ldap_err2string(rc) << std::endl;
        ldap_unbind_ext_s(ld, NULL, NULL);
        return 1;
    }
    
    std::cout << "LDAP connection and bind successful" << std::endl;
    
    // Perform LDAP search (simulating JNDI lookup)
    std::string base = "ou=users,dc=example,dc=com";
    std::string filter = "(objectClass=*)";
    LDAPMessage *result;
    
    rc = ldap_search_ext_s(ld, base.c_str(), LDAP_SCOPE_SUBTREE, filter.c_str(), NULL, 0, NULL, NULL, NULL, 0, &result);
    if (rc != LDAP_SUCCESS) {
        std::cerr << "LDAP search failed: " << ldap_err2string(rc) << std::endl;
    } else {
        std::cout << "LDAP search successful" << std::endl;
        ldap_msgfree(result);
    }
    
    // Unbind and free resources
    ldap_unbind_ext_s(ld, NULL, NULL);
    return 0;
}
