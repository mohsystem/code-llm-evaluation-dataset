#include <iostream>
#include <ldap.h>

using namespace std;

int main(int argc, char *argv[]) {
    if (argc != 3) {
        cerr << "Usage: " << argv[0] << " <username> <domain_component>" << endl;
        return 1;
    }

    string username = argv[1];
    string domainComponent = argv[2];

    LDAP *ld;
    LDAPMessage *result;
    LDAPMessage *entry;
    int rc;
    char *attr;
    BerElement *ber;
    char **vals;

    // Initialize LDAP
    if (ldap_initialize(&ld, "ldap://localhost") != LDAP_SUCCESS) {
        cerr << "LDAP initialization failed" << endl;
        return 1;
    }

    // Bind to the server
    if (ldap_simple_bind_s(ld, NULL, NULL) != LDAP_SUCCESS) {
        cerr << "LDAP bind failed" << endl;
        ldap_unbind_ext_s(ld, NULL, NULL);
        return 1;
    }

    // Construct the search base DN
    string baseDn = "dc=" + domainComponent;
    replace(baseDn.begin(), baseDn.end(), '.', ',');
    baseDn = "dc=" + baseDn;

    // Construct the search filter
    string searchFilter = "(sAMAccountName=" + username + ")";

    // Perform the search
    rc = ldap_search_ext_s(ld, baseDn.c_str(), LDAP_SCOPE_SUBTREE,
                          searchFilter.c_str(), NULL, 0,
                          NULL, NULL, NULL, 0, &result);

    if (rc == LDAP_SUCCESS) {
        if (ldap_count_entries(ld, result) > 0) {
            entry = ldap_first_entry(ld, result);
            while (entry != NULL) {
                // Get the DN of the entry
                char *dn = ldap_get_dn(ld, entry);
                cout << "dn: " << dn << endl;
                ldap_memfree(dn);

                // Iterate over the attributes
                for (attr = ldap_first_attribute(ld, entry, &ber);
                     attr != NULL; attr = ldap_next_attribute(ld, entry, ber)) {
                    // Get the values of the attribute
                    vals = ldap_get_values(ld, entry, attr);
                    if (vals != NULL) {
                        cout << attr << ": ";
                        for (int i = 0; vals[i] != NULL; i++) {
                            cout << vals[i] << " ";
                        }
                        cout << endl;
                        ldap_value_free(vals);
                    }
                    ldap_memfree(attr);
                }
                cout << endl;
                entry = ldap_next_entry(ld, entry);
            }
        } else {
            cout << "User not found." << endl;
        }
        ldap_msgfree(result);
    } else {
        cerr << "LDAP search failed: " << ldap_err2string(rc) << endl;
    }

    ldap_unbind_ext_s(ld, NULL, NULL);
    return 0;
}