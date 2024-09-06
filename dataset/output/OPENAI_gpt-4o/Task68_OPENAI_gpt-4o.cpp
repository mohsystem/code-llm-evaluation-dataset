#include <iostream>
#include <ldap.h>
#include <string>
#include <vector>
#include <json/json.h>

int main(int argc, char *argv[]) {
    std::string domainComponent = argv[1];
    std::string username = argv[2];

    std::string query = "(uid=" + username + ")";
    
    LDAP *ld;
    LDAPMessage *result, *entry;
    int ldap_version = LDAP_VERSION3;

    if (ldap_initialize(&ld, "ldap://localhost") != LDAP_SUCCESS) {
        std::cerr << "LDAP initialization failed" << std::endl;
        return 1;
    }

    ldap_set_option(ld, LDAP_OPT_PROTOCOL_VERSION, &ldap_version);

    if (ldap_simple_bind_s(ld, nullptr, nullptr) != LDAP_SUCCESS) {
        std::cerr << "LDAP bind failed" << std::endl;
        return 1;
    }

    std::string base_dn = "dc=" + domainComponent;
    if (ldap_search_ext_s(ld, base_dn.c_str(), LDAP_SCOPE_SUBTREE, query.c_str(), nullptr, 0, nullptr, nullptr, nullptr, LDAP_NO_LIMIT, &result) != LDAP_SUCCESS) {
        std::cerr << "LDAP search failed" << std::endl;
        return 1;
    }

    entry = ldap_first_entry(ld, result);
    if (entry == nullptr) {
        std::cerr << "No entries found" << std::endl;
    } else {
        Json::Value root;
        for (entry = ldap_first_entry(ld, result); entry != nullptr; entry = ldap_next_entry(ld, entry)) {
            Json::Value userInfo;
            char *dn = ldap_get_dn(ld, entry);
            userInfo["dn"] = dn;
            root.append(userInfo);
            ldap_memfree(dn);
        }
        std::cout << root.toStyledString() << std::endl;
    }

    ldap_msgfree(result);
    ldap_unbind_ext_s(ld, nullptr, nullptr);
    return 0;
}