// C++ does not have a built-in XML parsing library, so we'll use the Xerces-C++ library
// This code assumes you have the Xerces-C++ library installed and linked

#include <xercesc/parsers/XercesDOMParser.hpp>
#include <xercesc/dom/DOM.hpp>
#include <xercesc/util/PlatformUtils.hpp>

#include <iostream>

int main() {
    try {
        xercesc::XMLPlatformUtils::Initialize();
        XercesDOMParser* parser = new XercesDOMParser();
        parser->parse("xml_string.xml"); // replace with your XML string
        xercesc::DOMDocument* doc = parser->adoptDocument();
        xercesc::DOMElement* root = doc->getDocumentElement();
        std::cout << root->getTagName() << std::endl;
        delete parser;
        xercesc::XMLPlatformUtils::Terminate();
    } catch (const xercesc::XMLException& e) {
        std::cerr << "Error: " << e.getMessage() << std::endl;
        return 1;
    }
    return 0;
}