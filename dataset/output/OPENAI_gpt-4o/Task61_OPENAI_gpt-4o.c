#include <stdio.h>
#include <libxml/parser.h>
#include <libxml/tree.h>

int main() {
    char *xmlContent = "<root><child>value</child></root>";
    xmlDoc *doc = xmlReadMemory(xmlContent, strlen(xmlContent), "noname.xml", NULL, 0);
    if (doc == NULL) {
        printf("Failed to parse XML
");
        return -1;
    }
    xmlNode *root_element = xmlDocGetRootElement(doc);
    printf("Root element: %s
", root_element->name);
    xmlFreeDoc(doc);
    xmlCleanupParser();
    return 0;
}