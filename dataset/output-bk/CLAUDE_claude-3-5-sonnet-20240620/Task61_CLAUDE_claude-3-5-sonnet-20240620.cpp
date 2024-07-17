
#include <iostream>
#include <string>
#include <tinyxml2.h>

using namespace tinyxml2;

XMLElement* parseXMLString(const std::string& xmlString) {
    XMLDocument doc;
    doc.Parse(xmlString.c_str());
    return doc.RootElement();
}

int main() {
    std::string xmlString = "<root><child1>Value1</child1><child2>Value2</child2></root>";
    XMLElement* rootElement = parseXMLString(xmlString);
    if (rootElement != nullptr) {
        std::cout << "Root element: " << rootElement->Name() << std::endl;
    }
    return 0;
}
