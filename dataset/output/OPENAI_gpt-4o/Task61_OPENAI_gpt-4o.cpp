#include <iostream>
#include <libxml/parser.h>
#include <libxml/tree.h>

int main() {
    const char* xmlContent = "<root><child>value</child></root>";
    xmlDocPtr doc = xmlReadMemory(xmlContent, strlen(xmlContent), "noname.xml", NULL, 0);
    if (doc == NULL) {
        std::cerr << "Failed to parse XML" << std::endl;
        return -1;
    }
    xmlNodePtr root_element = xmlDocGetRootElement(doc);
    std::cout << "Root element: " << root_element->name << std::endl;
    xmlFreeDoc(doc);
    xmlCleanupParser();
    return 0;
}