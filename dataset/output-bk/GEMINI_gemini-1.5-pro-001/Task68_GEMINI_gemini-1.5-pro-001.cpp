#include <iostream>
#include <ldap++.h>

using namespace std;

int main(int argc, char *argv[]) {
    if (argc != 3) {
        cerr << "Usage: " << argv[0] << " <domain> <username>" << endl;
        return 1;
    }

    string domainComponent = argv[1];
    string username = argv[2];

    string ldapQuery = "(sAMAccountName=" + username + ")";
    string searchBase = "dc=" + domainComponent;

    for (char& c : searchBase) {
        if (c == '.') {
            c = ',';
        }
    }

    LDAP *ld;
    try {
        ld = new LDAP("localhost", 389);
        ld->bind("cn=Manager,dc=example,dc=com", "password");

        LDAPSearchResults *searchResult = ld->search(searchBase, LDAPAsynConnection::SEARCH_SUB, ldapQuery);

        if (searchResult->entryCount() > 0) {
            LDAPEntry *entry = searchResult->getNext();
            cout << "dn: " << entry->getDN() << endl;
            LDAPAttributeList *attributes = entry->getAttributes();
            for (auto const& attr : *attributes) {
                cout << attr.first << ": " << attr.second << endl;
            }
        } else {
            cout << "User not found." << endl;
        }

        delete searchResult;
        delete ld;
    } catch (LDAPException& e) {
        cerr << "LDAP Error: " << e.what() << endl;
        return 1;
    }

    return 0;
}