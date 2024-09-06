
#include <iostream>
#include <string>
#include <vector>
#include <ldap.h>

std::pair<std::string, std::string> extractDcAndUsername(const std::string& inputString) {
    size_t atPos = inputString.find('@');
    std::string username = inputString.substr(0, atPos);
    std::string domain = inputString.substr(atPos + 1);

    std::string dc;
    size_t pos = 0;
    std::string token;
    while ((pos = domain.find('.')) != std::string::npos) {
        token = domain.substr(0, pos);
        dc += "dc=" + token + ",";
        domain.erase(0, pos + 1);
    }
    dc += "dc=" + domain;

    return {username, dc};
}

void searchLDAP(const std::string& username, const std::string& dc) {
    LDAP* ld;
    int rc = ldap_initialize(&ld, "ldap://localhost:389");
    if (rc != LDAP_SUCCESS) {
        std::cerr << "LDAP init failed: " << ldap_err2string(rc) << std::endl;
        return;
    }

    rc = ldap_set_option(ld, LDAP_OPT_PROTOCOL_VERSION, &(const int){LDAP_VERSION3});
    if (rc != LDAP_OPT_SUCCESS) {
        std::cerr << "ldap_set_option failed!" << std::endl;
        ldap_unbind_ext_s(ld, nullptr, nullptr);
        return;
    }

    std::string filter = "(sAMAccountName=" + username + ")";
    char* attrs[] = {const_cast<char*>("*"), nullptr};

    LDAPMessage* res;
    rc = ldap_search_ext_s(ld, dc.c_str(), LDAP_SCOPE_SUBTREE, filter.c_str(), attrs, 0, nullptr, nullptr, nullptr, 0, &res);

    if (rc != LDAP_SUCCESS) {
        std::cerr << "LDAP search error: " << ldap_err2string(rc) << std::endl;
    } else {
        LDAPMessage* entry = ldap_first_entry(ld, res);
        if (entry != nullptr) {
            std::cout << "User Information:" << std::endl;
            BerElement* ber;
            char* attribute;
            for (attribute = ldap_first_attribute(ld, entry, &ber);
                 attribute != nullptr;
                 attribute = ldap_next_attribute(ld, entry, ber)) {
                berval** vals = ldap_get_values_len(ld, entry, attribute);
                if (vals != nullptr) {
                    for (int i = 0; vals[i] != nullptr; i++) {
                        std::cout << attribute << ": " << vals[i]->bv_val << std::endl;
                    }
                    ldap_value_free_len(vals);
                }
                ldap_memfree(attribute);
            }
            if (ber != nullptr) {
                ber_free(ber, 0);
            }
        } else {
            std::cout << "User not found." << std::endl;
        }
        ldap_msgfree(res);
    }

    ldap_unbind_ext_s(ld, nullptr, nullptr);
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <username@domain.com>" << std::endl;
        return 1;
    }

    std::string inputString = argv[1];
    auto [username, dc] = extractDcAndUsername(inputString);

    searchLDAP(username, dc);

    return 0;
}
