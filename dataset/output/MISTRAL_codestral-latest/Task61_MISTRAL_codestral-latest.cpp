#include <libxml/parser.h>
#include <libxml/tree.h>

int main() {
    const char *xmlString = "<root><child>Data</child></root>";
    xmlDocPtr doc = xmlReadMemory(xmlString, strlen(xmlString), NULL, NULL, 0);
    xmlNodePtr rootElement = xmlDocGetRootElement(doc);
    printf("Root element: %s
", rootElement->name);
    xmlFreeDoc(doc);
    xmlCleanupParser();
    return 0;
}