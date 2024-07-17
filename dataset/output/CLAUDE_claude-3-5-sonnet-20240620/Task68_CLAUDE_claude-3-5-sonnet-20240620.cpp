
#include <iostream>
#include <string>
#include <ldap.h>

#define MAX_LENGTH 256

int main(int argc, char *argv[]) {
    if (argc != 3) {
        std::cout << "Usage: " << argv[0] << " <domain> <username>" << std::endl;
        return 1;
    }

    std::string domain = argv[1];
    std::string username = argv[2];

    LDAP *ld;
    int rc;
    std::string ldap_uri = "ldap://localhost:389";
    std::string base_dn = "dc=" + domain;
    size_t pos = 0;
    while ((pos = base_dn.find(".", pos)) != std::string::npos) {
        base_dn.replace(pos, 1, ",dc=");
        pos += 4;
    }

    std::string search_filter = "(uid=" + username + ")";

    rc = ldap_initialize(&ld, ldap_uri.c_str());
    if (rc != LDAP_SUCCESS) {
        std::cerr << "ldap_initialize failed: " << ldap_err2string(rc) << std::endl;
        return 1;
    }

    rc = ldap_simple_bind_s(ld, NULL, NULL);
    if (rc != LDAP_SUCCESS) {
        std::cerr << "ldap_simple_bind_s failed: " << ldap_err2string(rc) << std::endl;
        ldap_unbind_ext_s(ld, NULL, NULL);
        return 1;
    }

    LDAPMessage *result;
    char *attrs[] = {"*", NULL};
    rc = ldap_search_ext_s(ld, base_dn.c_str(), LDAP_SCOPE_SUBTREE, search_filter.c_str(), attrs, 0, NULL, NULL, NULL, 0, &result);
    if (rc != LDAP_SUCCESS) {
        std::cerr << "ldap_search_ext_s failed: " << ldap_err2string(rc) << std::endl;
        ldap_unbind_ext_s(ld, NULL, NULL);
        return 1;
    }

    int num_entries = ldap_count_entries(ld, result);
    if (num_entries == 0) {
        std::cout << "User not found" << std::endl;
    } else {
        LDAPMessage *entry = ldap_first_entry(ld, result);
        BerElement *ber;
        char *attribute;
        char **values;

        std::cout << "User information:" << std::endl;
        for (attribute = ldap_first_attribute(ld, entry, &ber);
             attribute != NULL;
             attribute = ldap_next_attribute(ld, entry, ber)) {
            values = ldap_get_values(ld, entry, attribute);
            if (values != NULL) {
                std::cout << attribute << ": " << values[0] << std::endl;
                ldap_value_free(values);
            }
            ldap_memfree(attribute);
        }
        if (ber != NULL) {
            ber_free(ber, 0);
        }
    }

    ldap_msgfree(result);
    ldap_unbind_ext_s(ld, NULL, NULL);
    return 0;
}
