#include <iostream>
#include <libxml/parser.h>
#include <libxml/tree.h>

int main() {
    const char *xmlString = "<root><child>Data</child></root>";
    xmlDocPtr doc = xmlReadMemory(xmlString, strlen(xmlString), NULL, NULL, 0);
    if (doc == NULL) {
        fprintf(stderr, "Failed to parse document\n");
        return 1;
    }
    xmlNodePtr root_element = xmlDocGetRootElement(doc);
    std::cout << "Root element: " << root_element->name << std::endl;
    xmlFreeDoc(doc);
    xmlCleanupParser();
    return 0;
}