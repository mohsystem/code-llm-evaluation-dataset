#include <stdio.h>
#include <ldap.h>

#define LDAP_HOST "localhost"
#define LDAP_PORT 389

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <domain> <username>
", argv[0]);
        return 1;
    }

    char *domainComponent = argv[1];
    char *username = argv[2];

    LDAP *ld;
    LDAPMessage *result;
    LDAPMessage *entry;
    char *attrs[] = {"cn", "mail", NULL};
    struct ldapmsg *attribute;
    char *dn;
    char *a;
    BerElement *ber;
    char **vals;
    int i;

    char filter[256];
    snprintf(filter, sizeof(filter), "(&(objectClass=user)(sAMAccountName=%s))", username);

    char base[256];
    snprintf(base, sizeof(base), "dc=%s", domainComponent);
    char *basePtr = base;
    for (char *p = basePtr; *p; ++p) {
        if (*p == '.') {
            *p = ',';
            *(++p) = 'd';
            *(++p) = 'c';
            *(++p) = '=';
        }
    }

    if (ldap_initialize(&ld, "ldap://localhost:389") != LDAP_SUCCESS) {
        fprintf(stderr, "ldap_initialize failed
");
        return 1;
    }

    int rc = ldap_simple_bind_s(ld, NULL, NULL);
    if (rc != LDAP_SUCCESS) {
        fprintf(stderr, "ldap_simple_bind_s: %s
", ldap_err2string(rc));
        ldap_unbind_s(ld);
        return 1;
    }

    rc = ldap_search_s(ld, base, LDAP_SCOPE_SUBTREE, filter, attrs, 0, &result);
    if (rc != LDAP_SUCCESS) {
        fprintf(stderr, "ldap_search_s: %s
", ldap_err2string(rc));
        ldap_msgfree(result);
        ldap_unbind_s(ld);
        return 1;
    }

    if (ldap_count_entries(ld, result) > 0) {
        entry = ldap_first_entry(ld, result);
        dn = ldap_get_dn(ld, entry);
        printf("dn: %s
", dn);
        ldap_memfree(dn);

        for (a = ldap_first_attribute(ld, entry, &ber); a != NULL; a = ldap_next_attribute(ld, entry, ber)) {
            vals = ldap_get_values(ld, entry, a);
            printf("%s:", a);
            for (i = 0; vals[i]; i++) {
                printf(" %s", vals[i]);
            }
            printf("
");
            ldap_value_free(vals);
            ldap_memfree(a);
        }
    } else {
        printf("User not found.
");
    }

    ldap_msgfree(result);
    ldap_unbind_s(ld);
    return 0;
}