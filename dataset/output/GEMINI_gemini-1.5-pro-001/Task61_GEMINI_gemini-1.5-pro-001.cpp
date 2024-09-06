#include <iostream>
#include <string>
#include "pugixml.hpp"

using namespace std;

string getRootElement(const string& xmlString) {
    pugi::xml_document doc;
    pugi::xml_parse_result result = doc.load_string(xmlString.c_str());
    if (result) {
        return doc.root().name();
    } else {
        cerr << "XML parsing error: " << result.description() << endl;
        return "";
    }
}

int main() {
    string xmlString = "<note><to>Tove</to><from>Jani</from><heading>Reminder</heading><body>Don't forget me this weekend!</body></note>";
    string rootElement = getRootElement(xmlString);
    cout << rootElement << endl;
    return 0;
}