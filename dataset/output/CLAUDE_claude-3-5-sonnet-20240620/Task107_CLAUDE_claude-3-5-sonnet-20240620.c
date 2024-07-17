
#include <stdio.h>
#include <stdlib.h>
#include <ldap.h>

int main() {
    LDAP *ld;
    int rc;
    char *ldapuri = "ldap://localhost:389";
    
    // Initialize LDAP connection
    rc = ldap_initialize(&ld, ldapuri);
    if (rc != LDAP_SUCCESS) {
        fprintf(stderr, "LDAP initialization failed: %s\
", ldap_err2string(rc));
        return 1;
    }
    
    // Perform simple bind
    rc = ldap_simple_bind_s(ld, "cn=admin,dc=example,dc=com", "admin_password");
    if (rc != LDAP_SUCCESS) {
        fprintf(stderr, "LDAP bind failed: %s\
", ldap_err2string(rc));
        ldap_unbind_ext_s(ld, NULL, NULL);
        return 1;
    }
    
    printf("LDAP connection and bind successful\
");
    
    // Perform LDAP search (simulating JNDI lookup)
    char *base = "ou=users,dc=example,dc=com";
    char *filter = "(objectClass=*)";
    LDAPMessage *result;
    
    rc = ldap_search_ext_s(ld, base, LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, NULL, 0, &result);
    if (rc != LDAP_SUCCESS) {
        fprintf(stderr, "LDAP search failed: %s\
", ldap_err2string(rc));
    } else {
        printf("LDAP search successful\
");
        ldap_msgfree(result);
    }
    
    // Unbind and free resources
    ldap_unbind_ext_s(ld, NULL, NULL);
    return 0;
}
