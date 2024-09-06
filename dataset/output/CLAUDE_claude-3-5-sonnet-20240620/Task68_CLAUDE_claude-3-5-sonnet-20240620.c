
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ldap.h>

void extract_dc_and_username(const char* input, char* username, char* dc) {
    char* at_pos = strchr(input, '@');
    if (at_pos == NULL) {
        fprintf(stderr, "Invalid input format\\n");
        exit(1);
    }

    int username_len = at_pos - input;
    strncpy(username, input, username_len);
    username[username_len] = '\\0';

    char* domain = at_pos + 1;
    char* token;
    char* rest = domain;
    char temp_dc[256] = "";

    while ((token = strtok_r(rest, ".", &rest))) {
        strcat(temp_dc, "dc=");
        strcat(temp_dc, token);
        strcat(temp_dc, ",");
    }

    temp_dc[strlen(temp_dc) - 1] = '\\0';  // Remove the trailing comma
    strcpy(dc, temp_dc);
}

void search_ldap(const char* username, const char* dc) {
    LDAP* ld;
    int rc = ldap_initialize(&ld, "ldap://localhost:389");
    if (rc != LDAP_SUCCESS) {
        fprintf(stderr, "LDAP init failed: %s\\n", ldap_err2string(rc));
        return;
    }

    int version = LDAP_VERSION3;
    ldap_set_option(ld, LDAP_OPT_PROTOCOL_VERSION, &version);

    char filter[256];
    snprintf(filter, sizeof(filter), "(sAMAccountName=%s)", username);

    char* attrs[] = {"*", NULL};
    LDAPMessage* res;

    rc = ldap_search_ext_s(ld, dc, LDAP_SCOPE_SUBTREE, filter, attrs, 0, NULL, NULL, NULL, 0, &res);

    if (rc != LDAP_SUCCESS) {
        fprintf(stderr, "LDAP search error: %s\\n", ldap_err2string(rc));
    } else {
        LDAPMessage* entry = ldap_first_entry(ld, res);
        if (entry != NULL) {
            printf("User Information:\\n");
            BerElement* ber;
            char* attribute;
            for (attribute = ldap_first_attribute(ld, entry, &ber);
                 attribute != NULL;
                 attribute = ldap_next_attribute(ld, entry, ber)) {
                struct berval** vals = ldap_get_values_len(ld, entry, attribute);
                if (vals != NULL) {
                    for (int i = 0; vals[i] != NULL; i++) {
                        printf("%s: %s\\n", attribute, vals[i]->bv_val);
                    }
                    ldap_value_free_len(vals);
                }
                ldap_memfree(attribute);
            }
            if (ber != NULL) {
                ber_free(ber, 0);
            }
        } else {
            printf("User not found.\\n");
        }
        ldap_msgfree(res);
    }

    ldap_unbind_ext_s(ld, NULL, NULL);
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <username@domain.com>\\n", argv[0]);
        return 1;
    }

    char username[256];
    char dc[256];

    extract_dc_and_username(argv[1], username, dc);
    search_ldap(username, dc);

    return 0;
}
