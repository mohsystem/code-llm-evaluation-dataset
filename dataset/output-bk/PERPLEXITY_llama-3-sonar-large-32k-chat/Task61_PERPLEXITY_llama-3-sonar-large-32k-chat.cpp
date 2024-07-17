#include <libxml/parser.h>
#include <iostream>

int main() {
    xmlInitParser();
    xmlDoc *doc = htmlReadMemory("<root><person><name>John</name><age>30</age></person></root>", 44, NULL);
    if (doc == NULL) {
        std::cerr << "Could not parse document" << std::endl;
        return 1;
    }
    xmlNode *root_element = xmlDocGetRootElement(doc);
    if (root_element == NULL) {
        std::cerr << "empty document" << std::endl;
        xmlFreeDoc(doc);
        return 1;
    }
    std::cout << "Root Element: " << root_element->name << std::endl;
    xmlFreeDoc(doc);
    xmlCleanupParser();
    return 0;
}