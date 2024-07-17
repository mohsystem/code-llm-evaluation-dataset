#include <stdio.h>
#include <ldap.h>

int main() {
    LDAP *ld;
    int rc;
    char *ldap_host = "ldap.example.com";
    char *ldap_port = "389";
    char *base_dn = "dc=example,dc=com";
    char *filter = "(objectClass=*)";

    ld = ldap_init(ldap_host, atoi(ldap_port));
    rc = ldap_bind_s(ld, NULL, NULL, LDAP_AUTH_SIMPLE);
    if (rc != LDAP_SUCCESS) {
        fprintf(stderr, "LDAP bind failed: %s
", ldap_err2string(rc));
        return 1;
    }

    LDAPMessage *result;
    rc = ldap_search_ext_s(ld, base_dn, LDAP_SCOPE_SUBTREE, filter, NULL, NULL, NULL, NULL, 0, &result);
    if (rc != LDAP_SUCCESS) {
        fprintf(stderr, "LDAP search failed: %s
", ldap_err2string(rc));
        return 1;
    }

    ldap_msgfree(result);
    ldap_unbind_ext(ld, NULL, NULL);
    return 0;
}