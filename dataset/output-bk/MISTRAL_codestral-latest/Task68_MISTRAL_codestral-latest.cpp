#include <iostream>
#include <ldap.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <dc> <username>" << std::endl;
        return 1;
    }

    std::string dc = argv[1];
    std::string username = argv[2];

    std::string ldap_uri = "ldap://localhost:389";
    std::string search_base = "dc=" + dc;
    std::string search_filter = "(uid=" + username + ")";

    LDAP *ldap_handle;
    int result = ldap_initialize(&ldap_handle, ldap_uri.c_str());

    if (result != LDAP_SUCCESS) {
        std::cerr << "Error: " << ldap_err2string(result) << std::endl;
        return 1;
    }

    struct ldap_message *search_result;
    result = ldap_search_s(ldap_handle, search_base.c_str(), LDAP_SCOPE_SUBTREE, search_filter.c_str(), NULL, 0, &search_result);

    if (result != LDAP_SUCCESS) {
        std::cerr << "Error: " << ldap_err2string(result) << std::endl;
        ldap_unbind_ext_s(ldap_handle, NULL, NULL);
        return 1;
    }

    if (ldap_count_entries(ldap_handle, search_result) > 0) {
        char *attribute_name = ldap_first_attribute(ldap_handle, ldap_first_entry(ldap_handle, search_result), NULL);

        while (attribute_name != NULL) {
            struct berval **values;
            ldap_get_values_len(ldap_handle, ldap_first_entry(ldap_handle, search_result), attribute_name, &values);
            std::cout << attribute_name << ": " << values[0]->bv_val << std::endl;
            ldap_value_free_len(values);
            attribute_name = ldap_next_attribute(ldap_handle, ldap_first_entry(ldap_handle, search_result), NULL);
        }
    } else {
        std::cout << "User not found." << std::endl;
    }

    ldap_msgfree(search_result);
    ldap_unbind_ext_s(ldap_handle, NULL, NULL);

    return 0;
}