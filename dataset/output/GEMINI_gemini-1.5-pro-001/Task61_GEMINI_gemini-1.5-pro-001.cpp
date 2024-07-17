#include <iostream>
#include <string>
#include <pugixml.hpp>

std::string getRootElement(const std::string& xmlString) {
    pugi::xml_document doc;
    pugi::xml_parse_result result = doc.load_string(xmlString.c_str());

    if (!result) {
        std::cerr << "Failed to parse XML: " << result.description() << std::endl;
        return "";
    }

    pugi::xml_node root = doc.first_child();
    return root.name();
}

int main() {
    std::string xmlString = "<note><to>Tove</to><from>Jani</from><heading>Reminder</heading><body>Don't forget me this weekend!</body></note>";
    std::string rootElement = getRootElement(xmlString);

    if (!rootElement.empty()) {
        std::cout << rootElement << std::endl;
    }

    return 0;
}