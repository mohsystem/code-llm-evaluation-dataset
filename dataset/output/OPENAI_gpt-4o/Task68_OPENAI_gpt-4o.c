#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ldap.h>

int main(int argc, char *argv[]) {
    char *domainComponent = argv[1];
    char *username = argv[2];
    LDAP *ld;
    LDAPMessage *result, *e;
    char *ldap_host = "localhost";
    int ldap_port = LDAP_PORT;
    int rc;
    char search_base[256], filter[256];
    
    sprintf(search_base, "DC=%s,DC=com", domainComponent);
    sprintf(filter, "(sAMAccountName=%s)", username);
    
    rc = ldap_initialize(&ld, "ldap://localhost");
    ldap_set_option(ld, LDAP_OPT_PROTOCOL_VERSION, LDAP_VERSION3);
    
    rc = ldap_search_ext_s(ld, search_base, LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, NULL, 100, &result);
    if (rc == LDAP_SUCCESS) {
        for (e = ldap_first_entry(ld, result); e != NULL; e = ldap_next_entry(ld, e)) {
            char *dn = ldap_get_dn(ld, e);
            printf("dn: %s
", dn);
            ldap_memfree(dn);
        }
        ldap_msgfree(result);
    } else {
        fprintf(stderr, "Error: %s
", ldap_err2string(rc));
    }
    
    ldap_unbind_ext(ld, NULL, NULL);
    return 0;
}